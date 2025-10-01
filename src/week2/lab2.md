# Part 1: git motivated
**git**: command line program that enables version control (in case you break it)

**Repository**: folder containing code

**GitHub**: website that holds (repos)itories; can contribute and share with others

# Part 2: SSH Keys on GitHub


 Recall from last lab how to log into your ieng6 account:

<code>
$ ssh <span class="code-replace-me" contenteditable>your account name</span>@ieng6.ucsd.edu
</code>

**Please log into ieng6.** Within your ieng6 account, use the following command to generate a new key pair, replacing `github_email` with your **GitHub email address**:

<code>
$ ssh-keygen -t rsa -b 4096 -C <span class="code-replace-me" contenteditable>github_email</span>
</code>

You’ll be prompted to “Enter a file in which to save the key”. Press Enter to accept the default location. You’ll then be prompted to enter a passphrase, which isn’t really necessary. Press Enter twice to continue without setting a passphrase. Though if you really want to set a passphrase, refer to [GitHub docs on passphrases](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/working-with-ssh-key-passphrases).

## Adding your SSH key to GitHub

By default, the public SSH key is saved to a file at `~/.ssh/id_rsa.pub`.

{: .note }
Instead of typing out the whole filename, you can type out some prefix of the name (e.g. `~/.ssh/id`), and **press Tab to autocomplete the name**.
In this case, tab complete won’t complete the full filename, since the private key happens to be named `id_rsa`.
*Please* be too lazy to type out entire filenames and use tab complete instead\!


**View the contents of** `~/.ssh/id_rsa.pub` **(using `cat`)**, then copy the contents of the public key file to your clipboard.

On the GitHub website, click your profile picture in the top right to open a menu, and click on “Settings”.

![Click on Settings in your GitHub account menu](./assets/github_settings.png)

On the left, open “SSH and GPG keys”, then click on “New SSH key”.

![Go to "New SSH key"](./assets/github_ssh.png)

Populate the fields as follows:

* **Title**: “ieng6”
  * The title doesn’t affect the functionality of the key, it’s just a note for you that this key is tied to your ieng6 account.
* **Key type**: “Authentication key”
* **Key**: Paste the contents of the public key file here (entire block including the email portion).

![Go to the "Key" box](./assets/github_add_new_key.png)

Click “Add SSH key”. You may need to confirm access to your account on GitHub at this point.

### Testing your SSH key

Finally, test your connection to GitHub with the command:

```
$ ssh -T git@github.com
```

If this is your first time connecting to GitHub, you might get a warning about the “authenticity of host can’t be established”. This is a warning for you to make sure that you’re connecting to the right thing. For the purposes of this lab, we assume that GitHub didn’t suddenly get hacked, so you can safely respond with “yes”. But if you’re really paranoid, you can check GitHub’s public key fingerprint [here](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/githubs-ssh-key-fingerprints).

After a successful connection, it should output `Hi <your-username>! You've successfully authenticated, but GitHub does not provide shell access`.


## Identify yourself to ieng6

With your current setup, each time you log in to your `ieng6` account, you have to type the password. This can get a bit tedious. Luckily, there is a cool and interesting way to avoid this while still staying secure using SSH keys. **You should perform the following on whichever device you don't want your password to be required for logging into ieng6** If you don't have your own device with you, please indicate this in your lab report and skip to the next section.

{: .important-title }
> Windows Users
>
> Please open a terminal in WSL before proceeding. Verify this by the prompt displayed in the terminal (It should *not* start with "`PS`", and it *should* end with `$`, not `>`). If you don't have WSL, you may still proceed with a PowerShell terminal, but you should [install WSL](/docs/setup.html) before the next lab.

1. Verify that you are **not** logged into `ieng6`. If your prompt does not contain the string `ieng6`, then you're probably not on it.
2. Run `ssh-keygen -t rsa`. This command will generate a pair of SSH keys for you: one public (ends in .pub) and one private.
   If the program claims that the keys already exist, answer the `Overwrite (y/n)?` prompt with `n` to prevent overwriting your existing keys. Otherwise, keep pressing `<Enter>` until the program shows some text it calls the "randomart image".
3. Expand the instructions that match your system below:

<details>
    <summary>
        <strong>If your prompt ends with $ or % or #, not > (macOS, WSL, Linux)</strong> (Click to show instructions)
    </summary>
    Run <code>ssh-copy-id <span class="code-replace-me" contenteditable>username</span>@ieng6.ucsd.edu</code>, and enter your password (one last time). The program should claim that it has installed your key.
</details>
<details>
    <summary>
        <strong>If your prompt ends with > (Windows)</strong> (Click to show instructions)
    </summary>
    <ol>
        <li>Log into ieng6 with <code>ssh</code> (using your password as usual)</li>
        <li>Run <code>mkdir -p .ssh</code> in the terminal</li>
        <li>Log out of your remote account by pressing <kbd>Ctrl</kbd>+<kbd>D</kbd> or typing <code>exit</code>.</li>
        <li>On your local machine, run the following command:<br />
           <code>type $env:USERPROFILE\.ssh\id_rsa.pub | ssh <span class="code-replace-me" contenteditable>username</span>@ieng6.ucsd.edu "cat >> .ssh/authorized_keys"</code><br />
           (Credit to <a href="https://chrisjhart.com/Windows-10-ssh-copy-id/">Christopher Hart</a> for this convenient command. Please note if the above command does not work, copy in your full path to the SSH key)
        </li>
    </ol>
</details>

Try to log onto your remote account again. **You shouldn’t be prompted for a password anymore.** If you are, ask for help and carefully review the steps above with your group.

