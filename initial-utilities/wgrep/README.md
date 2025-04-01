## wgrep

### Description
`wgrep` is a simple implementation of the Unix `grep` command, used to search for a pattern in a file.

### Usage
```sh
./wgrep <pattern> <file>
```
Example:
```sh
./wgrep hello sample.txt
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

The `test-wgrep.sh` script is just a wrapper for the `run-tests.sh` script in
the `tester` directory of this repository. This program has a few options; see
the relevant
[README](https://github.com/remzi-arpacidusseau/ostep-projects/blob/master/tester/README.md)
for details.
