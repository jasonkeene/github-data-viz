#!/usr/bin/env python

import json
import gzip
import os


def main():
    files = os.listdir('.')
    gzfiles = [f for f in files
               if f.endswith('.json.gz') and f + '.txt' not in files]

    for filename in gzfiles:
        print "reducing file:", filename
        repo_names = set()
        with gzip.open(filename, 'rb') as f:
            for line in f.readlines():
                data = json.loads(line)
                repo_names.add(data['repo']['name'])
        with open(filename + '.txt', 'w') as f:
            f.write("\n".join(repo_names) + "\n")


if __name__ == '__main__':
    main()
