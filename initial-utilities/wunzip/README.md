## wunzip

### Description
`wunzip` decompresses files that were compressed using `wzip`.

### Usage
```sh
./wunzip <compressed_file>
```
Example:
```sh
./wunzip sample.wz
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

The `test-wunzip.sh` script is just a wrapper for the `run-tests.sh` script in
the `tester` directory of this repository. This program has a few options; see
the relevant
[README](https://github.com/remzi-arpacidusseau/ostep-projects/blob/master/tester/README.md)
for details.
