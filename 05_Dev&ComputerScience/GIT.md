Here we have some git useful commands

## Configuration 

These two lines configure the name and the email of the user at 
the global level, we can act by configuring something on three levels: 
- `--local` acts on the current repository (.git/config)
- `--global` acts on all the repositories of the user (~/.gitconfig)
- `--system` acts on all the users of the system (/etc/gitconfig)

```bash
git config --global user.name "Claudio Simeoni"
git config --global user.email "cla.simeoni1990@gmail.com"
```

These three respectively do these things: ensuring that the default editor of git stuff is vscode and that it stays open, auto converting windows's files \r\n to \n, setting the main branch name to main instead of master because it is widely used today.

```bash
git config --global core.editor "code --wait"
git config --global core.autocrlf input
git config --global init.defaultBranch main
```

---
## Managing a Repo 

To create a repo you basically open a folder from the shell and type **`git init`** on it. This creates an hidden folder on your pc (.git) that setups everything for your repo to work. Now you can see in any time the status of your repo by using the command **`git status`**. 

By default every file in the repo is not tracked: to track one file (this mean you keep track of its changes) you just type **`git add namefile`** (you can also type `git add .` or `git add --all` to add all the files in the directory). To untrack a file you can use this command: `git rm --cached filename`. (To see which file are currently being tracked you can use `git ls-files`). 

---
## Gitignore

In addition you might want some of the files in the repo to be hidden, in order to do this you create a .gitignore file and you write different blocks of text in it depending on what you want to do: you can take a look to https://github.com/github/gitignore to have an overview of this.

The basic commands to add in a .gitignore file are the following: 

```bash
filename #to ignore a single file

*.extension #do ignore all the files with a single extension

dirname/ #to ignore a whole directory 
```

---
## Commit (impegno)

Once you added for the first time a file with `git add` this means that the file is currently being **tracked**. When you are working with files after a commit, the file are being tracked but they are in the **working directory**, then if you want to commit some of the files you modified you need to type `git add` once again to add the file to the **staging** (To remove a file from the staged ones you can use `git restore --staged filename`).

Every time you want to save the current status of the files in the staging you can use **`git commit -m "message"`**, to do so, you should add a message that contains the things you modified in that commit. (To bypass the staging phase you can simply type `git commit -a -m "message"`, this will commit every modified file). 

Every time you modify something you can see the differences from the last commit with **`git diff`**.

If you want to remove a file from the repo you can use **`git rm filename`**, what this does is that it both delete the file from the disk but also add the "removal" to the staging, it does basically `rm filename` followed by `git add`. Then if you want to restore the file you should firstly use `git restore --staged filename` to remove it from the staging and then you use `git restore filename` to fully restore it. 

---
## Log (registro)

To take a look at the previous commits you can use **`git log`**, for an abbreviated version you can use **`git log --oneline`**. (If you want to change the last commit's message you can use `git commit -m "newmessage" --amend`). If you want to see all the differences made by the single commits you can use **`git log -p`** (patch/toppa).

To revert the repo to a previous commit you can use the command **`git reset codeofthecommit`** (this doesn't bring the repository backwards, it is just useful to correct the commit). It exists a stronger version that brings the whole status of the repo to the one you select by adding the flag `--hard` after reset. In both cases the log will now on show only the commits before the one you selected but you can just type **`git reflog`** (reference log) to see all the commits. 

---
## Branches 

A branch is basically a temporary copy of the main branch where i can make updates that won't be added to the main branch, then only when i am sure of what i have done i can merge the new branch with the main one. 

To create a branch you can use **`git branch branchname`**, than to see which are the current branches you can use **`git branch`**, you'll see a little asterisk close to the branch you are currently on and to switch to another branch you can type **`git switch branchname`**. 

When you are currently in a branch you will see on you laptop the files with the current status of that branch. If you want to merge the changes made in branch B to branch A you need to switch to branch A and then use **`git merge -m "message" B`**. You can then delete a branch using **`git branch -d branchname`**. If by merging you come up with a conflict (meaning that both the current and the new branch have been modified) you can easily open the files where the conflicts occur and when you choose which modification to keep you can easily commit. 

If you are currently working on a branch and you do not want to lose all the modifications in the current branch when switching to another branch you can just use **`git stash`** to create a quick save of what you have done. 

```bash
git stash list   # Mostra gli stash salvati
git stash apply  # Riporta l’ultimo stash nei file
git stash drop   # Cancella l’ultimo stash
git stash pop    # Riporta lo stash e lo rimuove dalla lista
```