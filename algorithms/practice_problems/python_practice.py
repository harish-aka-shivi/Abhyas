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
ada_family = { 'Judith Blunt-Lytton': ['Anne Isabella Blunt', 'Wilfrid Scawen Blunt'],
              'Ada King-Milbanke': ['Ralph King-Milbanke', 'Fanny Heriot'],
              'Ralph King-Milbanke': ['Augusta Ada King', 'William King-Noel'],
              'Anne Isabella Blunt': ['Augusta Ada King', 'William King-Noel'],
              'Byron King-Noel': ['Augusta Ada King', 'William King-Noel'],
              'Augusta Ada King': ['Anne Isabella Milbanke', 'George Gordon Byron'],
              'George Gordon Byron': ['Catherine Gordon', 'Captain John Byron'],
              'John Byron': ['Vice-Admiral John Byron', 'Sophia Trevannion'] }

# Define a procedure, ancestors(genealogy, person), that takes as its first input
# a Dictionary in the form given above, and as its second input the name of a
# person. It should return a list giving all the known ancestors of the input
# person (this should be the empty list if there are none). The order of the list
# does not matter and duplicates will be ignored.

def ancestors(genealogy, person):
    if person not in genealogy:
        return [];

    a  = genealogy[person]
    for item in a:
        a = a + ancestors(genealogy,item)
        #print item + "  - >item "
    return a

#Test Cases
# Here are some examples:
print ancestors(ada_family, 'Augusta Ada King')
#>>> ['Anne Isabella Milbanke', 'George Gordon Byron',
#    'Catherine Gordon','Captain John Byron']

print ancestors(ada_family, 'Judith Blunt-Lytton')
#>>> ['Anne Isabella Blunt', 'Wilfrid Scawen Blunt', 'Augusta Ada King',
#    'William King-Noel', 'Anne Isabella Milbanke', 'George Gordon Byron',
#    'Catherine Gordon', 'Captain John Byron']
print ancestors(ada_family, 'Dave')
#>>> []

##############################################################################################################

# Khayyam Triangle

# The French mathematician, Blaise Pascal, who built a mechanical computer in
# the 17th century, studied a pattern of numbers now commonly known in parts of
# the world as Pascal's Triangle (it was also previously studied by many Indian,
# Chinese, and Persian mathematicians, and is known by different names in other
# parts of the world).

# The pattern is shown below:

#                    1
#                   1 1
#                  1 2 1
#                 1 3 3 1
#                1 4 6 4 1
#                   ...

# Each number is the sum of the number above it to the left and the number above
# it to the right (any missing numbers are counted as 0).

# Define a procedure, triangle(n), that takes a number n as its input, and
# returns a list of the first n rows in the triangle. Each element of the
# returned list should be a list of the numbers at the corresponding row in the
# triangle.


## By Recursion
def triangleRecursion(n):

    if n == 1:
        return [[1]]

    a = triangle(n-1)
    # print "a is ", a
    b = a[-1]
    c = []
    # print "b is equal",  b
    start = 0
    for item1 in range(0,len(b)):
        c.append(start+b[item1])
        start = b[item1]
    c.append(start+0)
    a.append(c)
    return a


def triangle(n):

    if n == 0:
        return []
    ans = [[1]]
    for item in range(2,n+1):
        a = ans[item-2]
        b = []
        start = 0
        for item1 in range(0,len(a)):
            b.append(start+a[item1])
            start = a[item1]
        b.append(start+0)
        ans.append(b)
    return ans

#Test Cases
#print triangle(0)
#>>> []

#print triangle(1)
#>>> [[1]]

#print triangle(2)
#>> [[1], [1, 1]]

print triangle(3)
#>>> [[1], [1, 1], [1, 2, 1]]

print triangle(6)
#>>> [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1], [1, 5, 10, 10, 5, 1]]
