## wzip

### Description
`wzip` compresses files using a simple run-length encoding algorithm.

### Usage
```sh
./wzip <file> > compressed.wz
```
Example:
```sh
./wzip sample.txt > sample.wz
```

### Compilation
```sh
make
```

### Testing
```sh
make test
```

### Clean
```sh
make clean
```

The `test-wzip.sh` script is just a wrapper for the `run-tests.sh` script in
the `tester` directory of this repository. This program has a few options; see
the relevant
[README](https://github.com/remzi-arpacidusseau/ostep-projects/blob/master/tester/README.md)
for details.
