#!/usr/bin/bash

if [ ! -w "/usr/bin" ]
then
    tput setaf 1
    echo "You does not have enough write permission for directory '/usr/bin'"
    echo "Installation terminated"
    exit 1
fi

if [ -d "$HOME/code-stats" ]
then
    rm -R "$HOME/code-stats"
fi

mkdir "$HOME/code-stats"
cp "./task.sh" "$HOME/code-stats/task.sh"

cp "./task.sh" "/usr/bin/code-stat"


# Add default extensions
> "$HOME/code-stats/extensions.txt"
echo "cs" >> "$HOME/code-stats/extensions.txt"
echo "java" >> "$HOME/code-stats/extensions.txt"
echo "py" >> "$HOME/code-stats/extensions.txt"
echo "js" >> "$HOME/code-stats/extensions.txt"
echo "ts" >> "$HOME/code-stats/extensions.txt"
echo "css" >> "$HOME/code-stats/extensions.txt"
echo "scss" >> "$HOME/code-stats/extensions.txt"
echo "html" >> "$HOME/code-stats/extensions.txt"

# Add default ignored folder names
> "$HOME/code-stats/ignores.txt"
echo "node_modules" >> "$HOME/code-stats/ignores.txt"

# export PATH=$PATH:$HOME/code-stats