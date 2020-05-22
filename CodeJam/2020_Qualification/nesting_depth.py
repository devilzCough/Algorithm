
t = int(input())
for i in range(t):
    s = list(input())

    pre = int(s[0])
    newS = '(' * pre + s[0]
    for c in s[1:]:
        cur = int(c)
        if pre > cur:
            cl = pre - cur
            pre -= cl
            newS += ')' * cl
        elif pre < cur:
            ol = cur - pre
            pre += ol
            newS += '(' * ol
        newS += c
    newS += ')' * pre
    print("Case #{}: {}" .format(i+1, newS))
