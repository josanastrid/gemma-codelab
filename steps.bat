@echo off
FOR /F %%G IN ('git rev-list --reverse origin/master')^
DO git reset --hard %%G & pause
