for commit in $(git rev-list origin/master | tail -r)
do
    git reset --hard $commit
    read -p "Press enter to continue..."
done