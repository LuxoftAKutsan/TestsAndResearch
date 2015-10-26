#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  generate_png.py
#
#  Copyright 2015 akutsan <akutsan@akutsan>
#
#  Generate PNG file with preloaded cycled content
#

dead_bief = [0xD, 0xE, 0xA, 0xD, 0xB, 0xE, 0xE, 0xF, 0x0]
size_in_bytes = 100
dead_bief = dead_bief * (size_in_bytes/len(dead_bief))
buf = ''.join(map(lambda x : chr(x), dead_bief))
f = open("dead_beef.png", "wb")
f.write(buf)
f.close()
