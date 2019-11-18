======
filter
======

.. image:: https://travis-ci.org/steinwurf/filter.svg?branch=master
    :target: https://travis-ci.org/steinwurf/filter

filter contains a basic kalman filter, but maybe more will be added later.

Use as Dependency in CMake
--------------------------

To depend on this project when using the CMake build system, add the following
in your CMake build script::

   add_subdirectory("/path/to/filter" filter)
   target_link_libraries(<my_target> steinwurf::filter)

Where ``<my_target>`` is replaced by your target.