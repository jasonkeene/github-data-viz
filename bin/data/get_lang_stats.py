#!/usr/bin/env python

import os

import redis
import requests


REDIS = redis.StrictRedis(host='localhost', port=6379, db=0)


def get_language_stats(repo_name):
    if REDIS.exists(repo_name) or REDIS.sismember('bad_repos', repo_name):
        print "skipping repo:", repo_name
        return

    print "getting repo:", repo_name
    url = "https://api.github.com/repos/{}/languages".format(repo_name)
    resp = requests.get(url, auth=(os.environ['TOKEN'], 'x-oauth-basic'))
    print resp.status_code

    stats = resp.json()
    if resp.status_code == 200 and not stats:
        REDIS.sadd('bad_repos', repo_name)
    else:
        REDIS.hmset(repo_name, stats)
    print "finished repo:", repo_name


def main():
    with open('most_common.txt') as f:
        repos = f.read().strip().split("\n")
    for repo_name in repos:
        get_language_stats(repo_name)


if __name__ == '__main__':
    main()
