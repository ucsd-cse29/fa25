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


# Lab Work Checkoff

To get the last one point for lab work checkoff this week, you just need to make a submission on Gradescope for `pa1`! 
