n, k, q = map(int, raw_input().split())
array = map(int, raw_input().split())
front = 0
front = (front - k) % n

for i in xrange(q):
    query = int(raw_input())
    ind = (front + query) % n
    print array[ind]
