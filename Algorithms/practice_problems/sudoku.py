
# Sudoku is a logic puzzle where a game
# is defined by a partially filled
# 9 x 9 square of digits where each square
# contains one of the digits 1,2,3,4,5,6,7,8,9.
# For this question we will generalize
# and simplify the game.

# check_sudoku takes as input a square list
# of lists representing an n x n
# sudoku puzzle solution and returns the boolean
# True if the input is a valid
# sudoku square and returns the boolean False
# otherwise.

# A valid sudoku square satisfies these
# two properties:

#   1. Each column of the square contains
#       each of the whole numbers from 1 to n exactly once.

#   2. Each row of the square contains each
#       of the whole numbers from 1 to n exactly once.

# You may assume the the input is square and contains at
# least one row and column.

correct = [[1,2,3],
           [2,3,1],
           [3,1,2]]

incorrect = [[1,2,3,4],
             [2,3,1,3],
             [3,1,2,3],
             [4,4,4,4]]

incorrect2 = [[1,2,3,4],
             [2,3,1,4],
             [4,1,2,3],
             [3,4,1,2]]

incorrect3 = [[1,2,3,4,5],
              [2,3,1,5,6],
              [4,5,2,1,3],
              [3,4,5,2,1],
              [5,6,4,3,2]]

incorrect4 = [['a','b','c'],
              ['b','c','a'],
              ['c','a','b']]

incorrect5 = [ [1, 1.5],
               [1.5, 1]]
               
def check_sudoku(square):
    size = len(square)
    sample = range(1,size+1)
    #print size, 'this is the size'
    # check for validity of input
    for item in square:
        starting_number = 1
        
        # check for items in rows
        for item1 in sample:
            if item1 not in item:
                return False
        
        
        for subitem in item:
            #print item
            #print 'item > size ', item > size
            #print 'is instance  ', isinstance(subitem,int)
            if subitem > size or not isinstance(subitem,int):
                return False
    
    #making another list
    transverse_square = []
    for item in square:
        a = []
        for subitem in item:
            a.append(subitem)
        transverse_square.append(a)
    
    #traversing a square       
    i = 0
    for item in square:
        j = 0
        for subitem in item:
            transverse_square[j][i] = square[i][j]  
            j = j+1
        i = i+1
        

    for item in transverse_square:
        starting_number = 1
        
        # check for items in rows
        for item1 in sample:
            if item1 not in item:
                return False
        
    return True


    
# TestCases    
print check_sudoku(incorrect)
#>>> False

print check_sudoku(correct)
#>>> True

print check_sudoku(incorrect2)
#>>> False

print check_sudoku(incorrect3)
#>>> False

print check_sudoku(incorrect4)
#>>> False

print check_sudoku(incorrect5)
#>>> False



