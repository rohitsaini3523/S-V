# unfication algorithm
def unify(x, y, s):
    if s == False:
        return False
    elif x == y:
        return s
    elif var(x):
        return unify_var(x, y, s)
    elif var(y):
        return unify_var(y, x, s)
    elif is_compound(x) and is_compound(y):
        return unify(x.args, y.args, unify(x.op, y.op, s))
    elif is_list(x) and is_list(y):
        return unify(x.rest, y.rest, unify(x.first, y.first, s))
    else:
        return False
def unify_var(var, x, s):
    if var in s:
        return unify(s[var], x, s)
    elif x in s:
        return unify(var, s[x], s)
    else:
        s[var] = x
        return s
def var(x):
    return isinstance(x, str) and x[0].isupper()
def is_compound(x):
    return isinstance(x, Compound)
def is_list(x):
    return isinstance(x, List)
class Compound:
    def __init__(self, op, args):
        self.op = op
        self.args = args
    def __str__(self):
        return self.op + '(' + ','.join(map(str, self.args)) + ')'
class List:
    def __init__(self, first, rest):
        self.first = first
        self.rest = rest
    def __str__(self):
        if self.rest == None:
            return str(self.first)
        else:
            return str(self.first) + ',' + str(self.rest)
if __name__ == '__main__':
    s = unify(Compound('f', ['X', 'Y']), Compound('f', [Compound('g', ['a']), 'b']), {})
    print(s)
        