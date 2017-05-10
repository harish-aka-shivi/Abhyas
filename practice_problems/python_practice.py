#iterative
def fibonacci(n):
    current  = 0;
    after = 1
    for i in range(0,n):
        #take place simultaneously
        current, after = after, current + after
    return current

#Very expensive calling function multiple times
def fibonacci(n):
    if n == 0:
        return 0;
    if n == 1:
        return 1;
    return fibonacci(n-1) + fibonacci(n-2)

#########################################################################333

def is_palindrome(s):
    if len(s) == 0:
        return True;

    if s[0] == s[-1]:
        return is_palindrome(s[1:-1])
    else:
        return False

print is_palindrome('')
#>>> True
print is_palindrome('abab')
#>>> False
print is_palindrome('abba')
#>>> True


###############################################################################
def antisymmetric(a):
    rows = len(a)
    i = 0;
    for item in range(rows):
        row = a[item]
        column = len(row)
        if column != rows:
            return False;

        for num in range(column):
            if a[i][num] != 0 and a[num][i] != 0 and a[i][num] != -a[num][i]:
                return False;

        i = i+ 1
    return True


# Test Cases:

print antisymmetric([[0, 1, 2],
                     [-1, 0, 3],
                     [-2, -3, 0]])
#>>> True

print antisymmetric([[0, 0, 0],
                     [0, 0, 0],
                     [0, 0, 0]])
#>>> True

print antisymmetric([[0, 1, 2],
                     [-1, 0, -2],
                     [2, 2,  3]])
#>>> False

print antisymmetric([[1, 2, 5],
                     [0, 1, -9],
                     [0, 0, 1]])
#>>> False

############################################################################
# Everyone answering this question will convince a number, spread, (input to
# the model) of their friends to take the course next offering. This will
# continue, so that all of the newly recruited students, as well as the original
# students, will convince spread of their
# friends to take the following offering of the course.
# recruited friends are unique, so there is no duplication among the newly
# recruited students. Define a procedure, hexes_to_udaciousness(n, spread,
# target), that takes three inputs: the starting number of Udacians, the spread
# rate (how many new friends each Udacian convinces to join each hexamester),
# and the target number, and outputs the number of hexamesters needed to reach
# (or exceed) the target.

def hexes_to_udaciousness(n, spread, target):
    if n >=  target:
        return 0
    return 1 + hexes_to_udaciousness(n*spread + n,spread,target)

# 0 more needed, since n already exceeds target
print hexes_to_udaciousness(100000, 2, 36230)
#>>> 0

# after 1 hexamester, there will be 50000 + (50000 * 2) Udacians
print hexes_to_udaciousness(50000, 2, 150000)
#>>> 1

# need to match or exceed the targetr
print hexes_to_udaciousness(50000, 2, 150001)
#>>> 2

# only 12 hexamesters (2 years) to world domination!
print hexes_to_udaciousness(20000, 2, 7 * 10 ** 9)
#>>> 12

# more friends means faster world domination!
print hexes_to_udaciousness(15000, 3, 7 * 10 ** 9)
#>>> 10




################################################################################

# Deep Count

# The built-in len operator outputs the number of top-level elements in a List,
# but not the total number of elements. For this question, your goal is to count
# the total number of elements in a list, including all of the inner lists.

# Define a procedure, deep_count, that takes as input a list, and outputs the
# total number of elements in the list, including all elements in lists that it
# contains.

def is_list(p):
    return isinstance(p, list)

def deep_count(p):
    lent = 0;
    for item in p:
        if is_list(item):
            lent = lent + deep_count(item)
    return lent + len(p)

print deep_count([1, 2, 3])
#>>> 3

# The empty list still counts as an element of the outer list
print deep_count([1, [], 3])
#>>> 3

print deep_count([1, [1, 2, [3, 4]]])
#>>> 7

print deep_count([[[[[[[[1, 2, 3]]]]]]]])
#>>> 10

#############################################################################
