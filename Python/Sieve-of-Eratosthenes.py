#!/usr/bin/env python3
# Sieve-of-Eratosthenes.py
"""Prime numbers using Sieve of Eratosthenes algorithm."""
import time

n = 1000
start = time.time()
primes = [True for _ in range(n)]
primes[0] = primes[1] = False

s = 2
while s * s <= n:
    if primes[s]:
        for j in range(s * s, n, s):
            primes[j] = False

    s += 1

stop = time.time()
for i, x in enumerate(primes):
    if x:
        print(i)

print('---------------------')
print('Took', round((stop - start) * 1000, 8), 'ms')
