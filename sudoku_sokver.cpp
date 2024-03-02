#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <type_traits>

// условие задачи https://leetcode.com/problems/sudoku-solver/description/

using namespace std;

class Solution {
public:
    //множество символов
    using hash_t = std::unordered_set<char>;
    
    using table_choose_t = std::vector<std::vector<hash_t>>;
    // ветка для возврата (запоминаем какие эл-ты были поставлены, история)
    std::stack<std::pair<int, int>> branch;
    //таблица множеств чисел, для выбора 
    table_choose_t table_digits;
    // числа доски по столбцам 
    std::vector<hash_t> columns;
    // числа доски по строкам 
    std::vector<hash_t> rows;
    // числа доски по квадратам 3x3
    std::vector<std::vector<hash_t>> quad;

    /// @brief содержит ли эл-т таблица выбора 
    /// @param _row - номер строки 
    /// @param _column - номер столбца 
    /// @return true - если таблица содержит числа, false - иначе 
    bool contains_in_sets_digits(int _row, int _column) {
        return !table_digits[_row][_column].empty();
    }

    //! объединить множества 
    static hash_t union_sets(const hash_t& _h1, const hash_t& _h2, const hash_t& _h3) {
        hash_t result;
        for(char ch : _h1) {
            result.insert(ch);
        }
        for(char ch : _h2) {
            result.insert(ch);
        }
        for(char ch : _h3) {
            result.insert(ch);
        }

        return result;
    } 
    // найти пересечение множеств 
    static hash_t intersec_sets(const hash_t& _h1, const hash_t& _h2, const hash_t& _h3) {
        hash_t result;
        for(char ch : _h1) {
            if (_h2.contains(ch) && _h3.contains(ch)) {
                result.insert(ch);
            }
        }
        for(char ch : _h2) {
            if (_h1.contains(ch) && _h3.contains(ch)) {
                result.insert(ch);
            }
        }

        for(char ch : _h3) {
            if (_h1.contains(ch) && _h2.contains(ch)) {
                result.insert(ch);
            }
        }

        return result;
    } 
    /// @brief находит пропущенное число во множестве 
    /// @param _h - множество чисел
    /// @note предполагается, что должно быть пропущено только одно число, 
    ///       в противном случае функция вернёт первое пропущенное 
    /// @return пропущенное число 
    static char missing_num(const hash_t& _h) {
        for(int i = 1; i <= 9; ++i) {
            if (!_h.contains('0' + i)) {
                return '0' + i;
            } 
        }

        return 'N';
    }
    /// @brief возвращает пропущенные числа во множестве \a h
    /// @param h - множество чисел 
    /// @return множество пропущенных чисел 
    static hash_t missing(const hash_t& h) {
        hash_t res;
        for(int i = 1; i <= 9; ++i) {
            if (!h.contains('0' + i)) {
                res.insert('0' + i);
            }
        }
        return res;  
    }

    void place_element(std::vector<std::vector<char>>&board, int _row, int _column, char _digit) {
        board[_row][_column] = _digit;
        
        rows[_row].insert(_digit);
        columns[_column].insert(_digit);
        quad[_row / 3][_column / 3].insert(_digit);
    }

    void remove_element(std::vector<std::vector<char>>&board, int _row, int _column, char _digit) {
        board[_row][_column] = '.';
        
        rows[_row].erase(_digit);
        columns[_column].erase(_digit);
        quad[_row / 3][_column / 3].erase(_digit);
    }
    
    /// @brief решает судоку
    /// @tparam _WithStack - true - если нужно использовать ветку истории вставки, false - иначе 
    /// @param board - доска 
    /// @return true - если никакой эл-т не конфликтует, false - иначе 
    template<bool _WithStack>
    std::conditional_t<_WithStack, bool, void> solve_det(vector<vector<char>>& board) {
        

        std::queue<std::pair<int, int>> q;

        // проходимся по всем эл-там таблицы и запоминаем те, 
        // для которых можно сразу поставить пропущенное число 
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }

                hash_t uset = union_sets(rows[i], columns[j], quad[i / 3][j / 3]);
                
                if constexpr (_WithStack) {
                    if (uset.size() == 9) {
                        return false;
                    }   
                }

                if (uset.size() == 8) {
                    if constexpr (_WithStack) {
                        branch.emplace(i, j);
                    }

                    char mch = missing_num(uset);
                    q.emplace(i, j);

                    place_element(board, i, j, mch);
                }
            }
        }


        while(!q.empty()) {
            auto [rw, clmn] = q.front();
            q.pop();
            

            // проходимся по строке, в которую был поставлен эл-т 
            for(int j = 0; j < 9; ++j) {
                if (board[rw][j] != '.') {
                    continue;
                }

                hash_t uset = union_sets(rows[rw], columns[j], quad[rw / 3][j / 3]);

                if constexpr (_WithStack) {
                    if (uset.size() == 9) {
                        return false;
                    }   
                }

                if (uset.size() == 8) {
                    
                    if constexpr (_WithStack) {
                        branch.emplace(rw, j);
                    }

                    char mch = missing_num(uset);

                    q.emplace(rw, j);

                    place_element(board, rw, j, mch);
                }
            }
        
            // проходимс по столбцу, в котором был поставлен эл-т 
            for(int i = 0; i < 9; ++i) {
                if (board[i][clmn] != '.') {
                    continue;
                }

                hash_t uset = union_sets(rows[i], columns[clmn], quad[i / 3][clmn / 3]);

                if constexpr (_WithStack) {
                    if (uset.size() == 9) {
                        return false;
                    }   
                }

                if (uset.size() == 8) {
                    
                    if constexpr (_WithStack) {
                        branch.emplace(i, clmn);
                    }

                    q.emplace(i, clmn);
                    char mch = missing_num(uset);
                    place_element(board, i, clmn, mch);
                }
            }
            
            int beg_i = rw - rw % 3; 
            int end_i = beg_i + 3;
            int beg_j = clmn - clmn % 3;
            int end_j = beg_j + 3;
            
            // проходимся по кадрату 3х3, где был поставлен эл-т 
            for(int i = beg_i; i < end_i; ++i) {
                for(int j = beg_j; j < end_j; ++j) {
                    if (board[i][j] != '.') {
                        continue;
                    }

                    hash_t uset = union_sets(rows[i], columns[j], quad[i / 3][j / 3]);
                    
                    if constexpr (_WithStack) {
                        if (uset.size() == 9) {
                            return false;
                        }   
                    }

                    if (uset.size() == 8) {
                    
                        if constexpr (_WithStack) {
                            branch.emplace(i, j);
                        }
                        
                        q.emplace(i, j);
                        char mch = missing_num(uset);
                        place_element(board, i, j, mch);
                    }
                }
            }
        }

        if constexpr (_WithStack) {
            return true;
        }
    }

    // признак завершения перебора эл-тов
    static bool is_finish(const std::vector<hash_t>& _h) {
        for(const auto& hash : _h) {
            if (hash.size() != 9) {
                return false;
            }
        }

        return true;
    }

    /// @brief возращает номер строки и столбца, в котором пропущено минимальное кол-во эл-тов
    /// @param board - доска 
    /// @return 
    std::pair<int, int> choose_minimal_element(const vector<vector<char>>& board) {
        std::pair<int, int> result_index;
        int min_sz = 10; 
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                hash_t iset = intersec_sets(missing(rows[i]), missing(columns[j]), missing(quad[i / 3][j / 3]));
                
                if (iset.size() < min_sz) {
                    min_sz = iset.size();
                    result_index = {i, j};
                } 
                
            }   
        }

        return result_index;

    }
    
    /// @brief функция возврата 
    /// @param board 
    void revert(vector<vector<char>>& board) {

        auto [i, j] = branch.top();
        
        while(!contains_in_sets_digits(i, j)) {
            branch.pop();
            
            char board_value = board[i][j];
            remove_element(board, i, j, board_value);


            i = branch.top().first;
            j = branch.top().second;
        } 

        

    
        // обработать поледний эл-т
        branch.pop();

        char board_value = board[i][j];

        remove_element(board, i, j, board_value);
        
        auto& curr_set = table_digits[i][j];
        
        char first_element = *curr_set.begin();
        curr_set.erase(curr_set.begin());

        place_element(board, i, j, first_element);
        

    }

    void solveSudoku(vector<vector<char>>& board) {
        columns.resize(9, hash_t{});
        rows.resize(9, hash_t{});
        quad.resize(3, std::vector<hash_t>(3, hash_t{}));
        table_digits.resize(9, std::vector<hash_t>(9, hash_t{}));

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') {
                    continue;
                }
                rows[i].insert(ch);
                columns[j].insert(ch);
                quad[i / 3][j / 3].insert(ch);        
            }
        }

        auto choose_proc = [this, &board](){
            auto[i, j] = choose_minimal_element(board);
                
            hash_t iset = intersec_sets(missing(rows[i]), missing(columns[j]), missing(quad[i / 3][j / 3]));
            
            branch.emplace(i, j);
            
            char first_digit = *iset.begin();
            iset.erase(iset.begin());
            place_element(board, i, j, first_digit);
            
            table_digits[i][j] = iset;
        };

        solve_det<false>(board);

        if (is_finish(columns)) {
            return;
        }

        choose_proc();

        while(!is_finish(columns)) {
            if (solve_det<true>(board) == false) {
                // если при решении возник конфликт 
                // откат изменений 
               revert(board);
                
            } else {
                if (!is_finish(columns)) {
                    choose_proc();
                } else {
                    break;
                }
            }

        }
         

    }
};
