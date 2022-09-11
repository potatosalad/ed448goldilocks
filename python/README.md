Installation
------------

The easiest way to install is to run the command:
```
pip install 'git+https://git.code.sf.net/p/ed448goldilocks/code#egg=edgold&subdirectory=python'
```

Usage
-----

This wraps the Ed448 code into a simple to use class, EDDSA448.  The
easiest way to geenrate a new key is to use the generate class method.

Example:
```
from edgold.ed448 import EDDSA448

key = EDDSA448.generate()
privkey = key.export(key('raw')
msg = b'This is a message to sign'
sig = key.sign(msg)

pubkey = key.public_key().export_key('raw')
key = EDDSA448(pub=pubkey)
key.verify(sig, msg)
```
