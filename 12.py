# 12. Делители
 


import sys

import itertools

def generate_candidates(n):
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]  # Достаточно для большинства задач
    candidates = set([1])

    for prime in primes:
        new_candidates = set()
        for candidate in candidates:
            power = prime
            while candidate * power <= n:
                new_candidates.add(candidate * power)
                power *= prime
        candidates.update(new_candidates)

    return candidates

def count_divisors(x):
    count = 0
    for i in range(1, int(x ** 0.5) + 1):
        if x % i == 0:
            count += 1
            if i != x // i:
                count += 1
    return count

def find_number_with_max_divisors(n):
    candidates = generate_candidates(n)
    max_divisors = 0
    result = 1

    for candidate in candidates:
        divisors = count_divisors(candidate)
        if divisors > max_divisors or (divisors == max_divisors and candidate > result):
            max_divisors = divisors
            result = candidate

    return result


def main():
    n = int(input())
    result = find_number_with_max_divisors(n)
    print(result)
    print(count_divisors(result))



if __name__ == '__main__':
    main()

