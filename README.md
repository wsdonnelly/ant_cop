run make
-Usage: pipe lem-in's out to ./ant_cop

Example: (from lem_in dir, using the generator to seperate ant_cop dir):
./generator --big > test.map && ./lem-in < test.map | ../ant_cop/./ant_cop

Or copy the binary to lem-in's root......

# ant_cop will check:
- if the same ant appears twice on the same
- if the same room appears twice on the same line
- if each ant takes a valid path
- if all ants wind up at the end room