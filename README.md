# LEETCODE-FAANG-PREP-Auto-Sync

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Git](https://img.shields.io/badge/GIT-E44C30?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)

---

## ## About This Repository

This repository is my personal collection of LeetCode solutions, focused on problems frequently asked in FAANG interviews. The solutions here are **automatically synced** from my LeetCode profile using a custom Python script.

The primary goal of this project was to eliminate the manual work of copying, pasting, and organizing solutions into a Git repository. Now, after solving a problem on LeetCode, my script automatically handles the entire process of fetching the code, creating a structured directory, and pushing it to this GitHub repo.



---

## ## How It Works

While the sync script itself is kept private, the automation is achieved through a combination of Python and command-line tools. Here’s a breakdown of the core concepts involved:

* **1. LeetCode GraphQL API**: The script interacts with LeetCode's internal GraphQL API. This is the same API the official website uses to load your submission history and problem details. By mimicking the web client's requests, the script can programmatically access:
    * A list of recent accepted submissions.
    * The complete source code for a specific submission.
    * Problem details like difficulty, title, and frontend ID.

* **2. Secure Credential Management**: To authenticate with the API, the script needs a `LEETCODE_SESSION` and `CSRF_TOKEN`. These are sensitive credentials and are **never** hardcoded. They are stored in a local `.env` file, which is listed in `.gitignore` to prevent them from ever being committed to the repository.

* **3. State Management**: To avoid creating duplicate commits for the same solution, the script maintains a state file (e.g., `.last_submission_id`). After successfully pushing a new solution, it records that submission's ID. On the next run, it only processes solutions newer than the one recorded.

* **4. Git Automation**: The script uses Python's `subprocess` module to run Git commands directly from the code. The standard workflow is:
    1.  `git pull` to sync with the remote repository.
    2.  `git add [new_solution_file]` to stage the new file.
    3.  `git commit -m "feat(difficulty): ✨ Solve ID. Title"` to create a descriptive commit.
    4.  `git push` to upload the changes.

---

## ## How to Build Your Own Sync Script

If you're inspired to build your own LeetCode auto-sync tool, here are the general steps to get you started:

#### **Prerequisites**
* Python 3 installed.
* Git installed and configured on your system.
* A LeetCode account.

#### **Steps**
1.  **Get API Credentials**: Log in to LeetCode, open your browser's developer tools (`F12`), go to the `Application` or `Storage` tab, and find your `LEETCODE_SESSION` and `csrftoken` values under the cookies for `leetcode.com`.

2.  **Write the Python Script**:
    * Use the `requests` library to make `POST` requests to LeetCode's GraphQL endpoint (`https://leetcode.com/graphql`).
    * Create functions to fetch your recent submissions and the details for a specific submission.
    * Use the `os` library to create the desired directory structure (e.g., `topic/difficulty/id-title/`).
    * Use the `subprocess` library to execute Git commands.

3.  **Secure Your Credentials**:
    * Install `python-dotenv` via pip (`pip install python-dotenv`).
    * Create a `.env` file to store your session and CSRF tokens.
    * **Crucially, add `.env` to your `.gitignore` file.**

4.  **Run and Automate**:
    * Run the script manually from your terminal whenever you want to sync.
    * For true automation, you can set up a scheduler (like `cron` on Linux/macOS or Task Scheduler on Windows) to run the script periodically.

---

## ## Repository Structure

The script automatically organizes solutions into the following structure, making it easy to navigate:

.
├── arrays/
│   ├── easy/
│   │   ├── 0001-two-sum/
│   │   │   └── solution.py
│   │   └── 0026-remove-duplicates-from-sorted-array/
│   │       └── solution.js
│   └── medium/
│       └── 0015-3sum/
│           └── solution.py
└── strings/
└── easy/
└── 0020-valid-parentheses/
└── solution.py

---

## 📞 Contact & Collaboration

All feedback, questions, and suggestions are welcome! The best way to contact me or contribute is through this repository's official channels:

* **🐛 Found a Bug or Have a Question?** Please **[open an issue](https://github.com/rtkmor/LEETCODE-FAANG-PREP-Auto-Sync/issues)**.

* **💡 Have an Idea or Want to Chat?** For more general conversation, sharing ideas, or asking broader questions, please **[start a discussion](https://github.com/rtkmor/LEETCODE-FAANG-PREP-Auto-Sync/discussions)**.

Using these channels helps keep our conversations organized and accessible to others who may have similar questions.
