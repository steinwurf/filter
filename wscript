#! /usr/bin/env python
# encoding: utf-8

APPNAME = 'filter'
VERSION = '1.2.0'


def build(bld):

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_FILTER_VERSION="{}"'.format(
            VERSION))

    bld.recurse('src/filter')

    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse('test')
        bld.recurse('examples')
