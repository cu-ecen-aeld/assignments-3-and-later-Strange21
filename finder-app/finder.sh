#!/bin/bash

# Check if exactly two arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: You must specify both the directory and the search string."
    exit 1
fi

filesdir=$1
searchstr=$2

# Check if the first argument is a valid directory
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a valid directory."
    exit 1
fi

# Initialize counters
total_files=0
total_matching_lines=0

# Loop over the files found by the find command directly
for file in $(find "$filesdir" -type f); do
    # Increment the file count
    total_files=$((total_files + 1))

    # Count the number of matching lines in the file
    matching_lines=$(grep -c "$searchstr" "$file")
    total_matching_lines=$((total_matching_lines + matching_lines))

    # Print the current file count and matching lines count
    # echo "The number of files are $total_files and the number of matching lines are $total_matching_lines"
done

# Print the final result after the loop
echo "The number of files are $total_files and the number of matching lines are $total_matching_lines"