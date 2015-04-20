#!/usr/bin/env python

from collections import Counter
import os


def main():
    c = Counter()
    gzfiles = [f for f in os.listdir('.') if f.endswith('.txt')]
    for filename in gzfiles:
        with open(filename) as f:
            c.update([l for l in f.read().split('\n') if l])
    # write to disk
    with open('most_common.txt', 'w') as f:
        for l in c.most_common(10000):
            f.write(l[0] + "\n")


if __name__ == '__main__':
    main()
