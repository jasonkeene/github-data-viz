#!/usr/bin/env python

import redis


REDIS = redis.StrictRedis(host='localhost', port=6379, db=0)
LANGUAGE_STATS = {}


def main():
    for repo_name in [n for n in REDIS.keys() if '/' in n]:
        stats = {}
        line_counts = REDIS.hgetall(repo_name)

        if 'documentation_url' in line_counts or 'block' in line_counts:
            continue

        total_lines = sum([int(x) for x in line_counts.values()])
        for language, line_count in line_counts.items():
            stats[language] = float(line_count) / total_lines * 100
        LANGUAGE_STATS[repo_name] = stats

    for repo_name, stats in LANGUAGE_STATS.items():
        line = []
        line.append(repo_name)
        for language, weight in stats.items():
            line.append(language)
            line.append(weight)
        print '\t'.join([str(x) for x in line])


if __name__ == '__main__':
    main()

