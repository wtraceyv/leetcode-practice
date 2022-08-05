# sudoku fun
# Coded on my own, listened to bare explanation/plan first 
# then implemented fairly nicely. Scored really well speed and memory

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_check = [collections.defaultdict(int) for chunk in range(9)]
        col_check = [collections.defaultdict(int) for chunk in range(9)]
        box_check = [collections.defaultdict(int) for chunk in range(9)]
        
        for row in range(9):
          for col in range(9):
            current_value = board[row][col]
            if current_value != '.':
              # add to corresponding spots in check dictionaries
              row_check[row][current_value] += 1
              col_check[col][current_value] += 1
              box_col = row // 3
              box_row = col // 3
              box_map_index = (box_row * 3) + box_col
              box_check[box_map_index][current_value] += 1
              # check for duplicates
              if row_check[row][current_value] > 1 or col_check[col][current_value] > 1 or box_check[box_map_index][current_value] > 1:
                return False
              
        return True