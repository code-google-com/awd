# Using sequences.txt files #


## Introduction ##

Several of the AWD2 exporters use a helper text file by default called sequences.txt to list the named animation sequences and their frame ranges to be included in exported AWD files. This is because these applications do not provide a way (at least not that is generally used) to create named sequences/timelines for separate animations. Instead, it is common practice among animators to create all the animation sequences in a single timeline. The sequences.txt specifies which frame ranges belong to which named sequence.

## How to use ##
Create a file that uses the format below to specify named sequences as frame ranges on a longer timeline. The file should normally be called "sequences.txt" and be placed in the same folder that the AWD file is being exported to, but it's possible to reconfigure this in the exporter settings dialogs.

The exporter plug-ins will look for this file and parse it to know how to split up the timeline into sequences, and what to name those sequences in the AWD file.

## Format ##
The format is a simple three-column look-up table with space-delimited fields, where each line represents a named sequence. The first column specifies the name and the next two the start and end frame respectively. Names should be ASCII only and anything else will generate undefined behavior.

```
<name> <start> <end>
```

Any number of lines like the one above may exist in a file, but only one per line. Frame ranges may overlap.

Lines starting with # (the hash/pound character) are comments and will be ignored.

```
# This line will be ignored since it starts with the "#" comment character
```

## Example ##

Below follows a simple example of a sequences.txt file with three sequences called "idle" (frames 0-15), "walk" (frames 16-43) and "run" (frames 44-70).

```
# Sequences for characters
# This file was written by John Doe (john@example.com)
idle 0 15
walk 16 43
run 44 70
```