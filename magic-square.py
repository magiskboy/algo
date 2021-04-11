def magic_square(n):
    ret = [[0 for _ in range(n)] for __ in range(n)]
    nn = n ** 2 + 1
    i, j = 0, n // 2

    for c in range(1, nn):
        ret[i][j] = c
        i, j = i - 1, j + 1
        if i == -1 and j == n:
            i, j = 1, n - 1
        else:
            if i == -1 or j == n:
                if i == -1:
                    i = n - 1
                if j == n:
                    j = 0
            elif ret[i][j] > 0:
                i, j = i + 2, j - 1
    return ret


if __name__ == '__main__':
    import time
    n = 221
    a = time.time()
    magic_square(n)
    print((time.time()-a) * 1000 * 1000)