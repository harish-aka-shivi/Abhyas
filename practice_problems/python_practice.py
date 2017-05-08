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
