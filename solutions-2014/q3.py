cases = int(raw_input())

for c in xrange(cases):
    m, n = map(int, raw_input().split())
    cy = map(int, raw_input().split())
    cx = map(int, raw_input().split())
    cy.sort(reverse=True)
    cx.sort(reverse=True)
    my = mx = 1
    iy = ix = total = 0

    while (iy + ix < len(cy) + len(cx)):
        if iy < len(cy) and (ix == len(cx) or cy[iy] >= cx[ix]):
            total += cy[iy] * mx
            my += 1
            iy += 1
        else:
            total += cx[ix] * my
            mx += 1
            ix += 1

    print total % 1000000007
