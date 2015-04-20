#!/usr/bin/env python

from gevent.pool import Pool
from gevent.monkey import patch_all
import requests

patch_all()


def get_url(url):
    print "getting url:", url
    filename = url.split('/')[-1]
    resp = requests.get(url)
    with open(filename, 'w') as f:
        f.write(resp.content)
    print "finished url:", url


def main():
    with open('json_urls.txt') as f:
        json_urls = f.read().strip().split('\n')
    p = Pool(20)
    p.map(get_url, json_urls)


if __name__ == '__main__':
    main()
