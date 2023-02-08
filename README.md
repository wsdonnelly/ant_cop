# Usage
`make`

- lem-in's output can be piped to ant-cop
- assume you're in the lem-in dir and ant_cop is in the same parent director
- eg.
`./lem-in < some.map | ../ant_cop/ant_cop`
- the generator maps are quite useful for checking the output
-eg. `./generator --big-superposition > test.map && ./lem-in < test.map | ../ant_cop/ant_cop`

# ant_cop will check:
- if the same ant appears twice on the same line
- if the same room appears twice on the same line
- if each ant takes a valid path
- if all ants wind up at the end room

# output
- if no errors are found ant_cop will output the number of lines used (useful when testing accuracy)
- if errors are found ant_cop will out put the nature of the error and the offending ants and line.
- this part is kind of a mess, but if errors are found it's useful to run the same map again that generated the errors
but this time write lem-in's out to a file. Then you can grep (etc) ant_cop's output aginst this file.
## notes:
This was written "rush style" so there are most likely many bugs, and the code is a bit of a mess.Please let me know if you find something or feel free to send me a pull request

_ant_cop does not check for map composition errors and assumes that this is handled by lem-in._
