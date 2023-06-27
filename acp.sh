#!/bin/bash

# Git add all files in the working directory
git add .

# Prompt user for the commit message
read -p "Enter the commit message: " commit_message

# Git commit with the provided message
git commit -m "$commit_message"

# Git push to the remote repository
git push
