#!/usr/bin/env python

from distutils.command.build import build
from distutils.core import setup

import os
import sys

libext = dict(darwin='.dylib').get(sys.platform, '.so')

class my_build(build):
    def run(self):
        build.run(self)
        if not self.dry_run:
            os.spawnlp(os.P_WAIT, 'sh', 'sh', '-c', 'cd .. && mkdir build && cd build && cmake .. && make')
            self.copy_file(os.path.join('..', 'build', 'src', 'libdecaf.0' + libext), os.path.join(self.build_lib, 'edgold', 'libdecaf.so'))

cmdclass = {}
cmdclass['build'] = my_build

setup(name='edgold',
      version='1.0',
      description='The Ed ECC Goldilocks Python wrapper',
      author='John-Mark Gurney',
      author_email='jmg@funkthat.com',
      #url='',
      cmdclass=cmdclass,
      packages=['edgold', ],
     )
