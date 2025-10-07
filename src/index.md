![doodle](./doodle.jpg)

# UCSD CSE29 FA25 Syllabus and Logistics

- [Aaron Schulman](https://cseweb.ucsd.edu/~schulman/) (Instructor)
- [Joe Gibbs Politz](https://jpolitz.github.io) (Instructor)

[Basics](#basics) -
[Staff &amp; Resources](#staff-resources) -
[Schedule](#schedule) -
[Course Components](#syllabus) -
[Grading](#grading) -
[Policies](#policy)

CSE 29 introduces you to the broad field of systems programming, including 1)
the basics of how programs execute on a computer, 2) programming in C with
direct access to memory and system calls, 3) software tools to manage and
interact with code and programs. All very cool stuff that makes every programmer
better!

## <a name="basics"></a> Basics

- Lecture (attend the one you're enrolled in):
  - Joe/A section: 10am [Center Hall 119](https://map.concept3d.com/?id=1005#!m/163044?share)
  - Aaron/B section: 1pm [Warren Lecture Hall 2005](https://map.concept3d.com/?id=1005#!m/246292?share)
- Discussions (attend either or both):
  - Mon 3pm [Center 115](https://map.concept3d.com/?id=1005#!m/163044?share)
  - Mon 4pm [Ledden Auditorium](https://map.concept3d.com/?id=1005#!m/639912?share)
- Labs: Tuesdays (check your schedule!). Either B240 or B250 in the [CSE building](https://map.concept3d.com/?id=1005#!m/164780?share)
- Exams: [AP&M Testing Center](https://map.concept3d.com/?id=1005#!m/167186?share), flexible scheduling in weeks 3, 6, and 9
- Final exam: [AP&M Testing Center](https://map.concept3d.com/?id=1005#!m/167186?share), flexible scheduling in final exam week
- Professor office hours – Joe and Aaron each have 2 hours. Come to either and
  ask anything you need.
    - Aaron: Monday 3:30pm-4:30pm and Wednesday 11am-12pm CSE3120
    - Joe: Tuesday 1:00pm-2:00pm (CSE B260 in the labs) and Wednesday 1:00-2:00pm (CSE 3206 Joe's Office)
- Office Hours: See the [Office Hours Calendar](#office-hours-calendar)
- Q&A forum: [Piazza](https://piazza.com/class/mfzu0oi0j2q354)
- PrairieLearn: [https://us.prairielearn.com](https://us.prairielearn.com)
- Textbook/readings: [Dive Into Systems](https://diveintosystems.org/book/), plus additional readings we will assign (all free/online)
  - Free: [MIT Missing Semester](https://missing.csail.mit.edu/)
  - Not free but pretty cheap: [Julia Evans Zines](https://wizardzines.com/), especially [The Pocket Guide to Debugging](https://wizardzines.com/zines/debugging-guide/)

## <a name="staff-resources"></a> Staff Resources

### Office Hours Calendar

<iframe src="https://calendar.google.com/calendar/embed?src=c_ae9767c348e966bfab21111de9970ad83a36f155ee0583d85874fde005ad9232%40group.calendar.google.com&ctz=America%2FLos_Angeles" style="border:solid 1px #777" width="800" height="600" frameborder="0" scrolling="no"></iframe>

## <a name="schedule"></a> Schedule

The schedule below outlines topics, due dates, and links to assignments. We'll
typically update the material for the upcoming week before Monday's lecture so
you can see what's coming.

### Week 2 - Number Representations, Sizes, and Signs

- **Readings**
  - [Binary and Data Representaion (Sec 4.1-4.6)](https://diveintosystems.org/book/C4-Binary/bases.html)
  - [Arrays in C](https://diveintosystems.org/book/C2-C_depth/arrays.html)
  - [Scanf](https://diveintosystems.org/book/C2-C_depth/IO.html#_scanf) and [fgets](https://diveintosystems.org/book/C2-C_depth/IO.html#_file_inputoutput) (though this week we'll only use `fgets` with `stdin`
 
- **Lecture Materials**

  - **Monday:**
    - [Repository](https://github.com/ucsd-cse29/fa25-05-w2m-bin-to-dec/tree/main)
    - <u>Joe's Lecture:</u> [Notes](lec/week2/Annotated-lecture-05-w2m.pdf)
    - <u>Aaron's Lecture:</u> [Slides](lec/week2/29-fa25-l5.pdf)

- **Lab**
  - [Lab 2 Reference](week2/lab2.md)

### Week 1 – Strings, Memory and Bitwise Representations (in C)

- **Announcements**

  - **Problem Set 1** will be available on [PrairieLearn](https://us.prairielearn.com/pl/course_instance/195644/assessments), after lab, due Mon Oct 6 at 11:59pm

- **Readings**
  - [The UNIX Command Line](https://diveintosystems.org/book/Appendix2/cmdln_basics.html)
  - [Arrays and Strings (In C)](https://diveintosystems.org/book/C1-C_intro/arrays_strings.html)
- **Bitwise Videos**

  - [Brief Bitwise Operators Intro](https://www.youtube.com/watch?v=iU-0YhRFf7Y)
  - [Counting 0 bits](https://www.youtube.com/watch?v=M5mVVJHpNQ8)

- **Lecture Materials**

  - **Friday:**

    - <u>Joe's Lecture:</u> [Notes](lec/week1/Annotated-lecture-04-w1f.pdf)
    - <u>Aaron's Lecture:</u> [Slides](lec/week1/29-fa25-l4.pdf)

  - **Wednesday:**

    - [Repository](https://github.com/ucsd-cse29/fa25-03-w1w-more-strings)
    - <u>Joe's Lecture:</u> [Notes](lec/week1/Annotated-lecture-03-w1w.pdf)
    - <u>Aaron's Lecture:</u> [Slides](lec/week1/29-fa25-l3.pdf)

  - **Monday:**
    - [Repository](https://github.com/ucsd-cse29/fa25-02-w1m-strings)
    - <u>Joe's Lecture:</u> [Notes](lec/week1/Annotated-lecture-02-w1m.pdf)
    - <u>Aaron's Lecture:</u> [Slides](lec/week1/29-fa25-l2.pdf)

- **Lab**
  - [Lab 1 Form and Reference](./week1/lab1.md)

### Week 0 – Welcome

- **Announcements**

  - Lab attendance is **required** and a lot happens there, make sure to go to lab.

- **Lecture Materials**
  - **Friday:**
    - <u>Joe's Lecture:</u> [Notes](lec/week0/Annotated-lecture-01-w0f.pdf)
    - <u>Aaron's Lecture:</u> [Slides](lec/week0/29-fa25-l1.pdf)

## Syllabus

There are several components to the course:

- **Lab sessions**
- **Lecture and discussion sessions**
- **Problem sets**
- **Assignments**
- **Exams**

### Labs

The course's lab component meets for 2 hours. In each lab you'll switch between
working on your own, working in pairs, and participating in group discussions
about your approach, lessons learned, programming problems, and so on.

The lab sessions and groups will be led by TAs and tutors, who will note your
participation in these discussions for credit. Note that you must
**participate**, not merely **attend**, for credit.

For each lab there are 4 possible points to earn:

- **1** for being present
- **2** for being an active, professional, productive participant while present
- **1** for submitting and/or getting work checked off that was done in lab

If you miss lab, you can earn the third point by submitting work late, but
cannot earn back the 3 points related to participation.

### Lecture and Discussion Sessions

Lecture sessions are on Monday, Wednesday, and Friday, and discussion sections
are Monday. We recommend attending every lecture and one of the two discussion
sections.

In a typical discussion section two things will happen:

- TAs will go over programming work in the problem sets, sometimes reviewing,
  sometimes doing work on the active problem set.
- There will be time to work on problem sets and ask questions of the TAs and
  your peers

### Problem Sets

On Mondays of even weeks (2, 4, 6, 8, 10), a _problem set_ is due.

Problem sets have a collection of small programming problems that provide
practice on concepts and techniques from lecture, lab, and the reading. In
addition, a subset of each problem set has programming problems that are
directly related to completing the current assignment (e.g. some of the code may
even be copy-pasteable).

### Assignments

The course has 5 **assignments** that involve programming and writing.
Individual assignments will have detailed information about submission
components; in general you'll submit some code and some written work (to
PrairieLearn).

For each assignment, we will give a **0-4** score along with feedback:

- **4** for a complete submission with high code and writing quality with few mistakes, and no significant errors
- **3** for a complete submission with some mistakes **or** some unclear writing
- **2** for a complete submission with some mistakes **and** some unclear writing, or a submission with high code or writing quality, but missing the other
- **1** for a submission missing key components, or with clear inaccuracies in multiple components
- **0** for no submission or a submission unrecognizable as a partial or complete submission

After each assignment is graded, you'll have a chance to _resubmit_ it based on
the feedback you received, which will detail what you need to do to increase
your score. You can increase your score by up to **2** points on resubmit (e.g.
0 to 2, 1 to 3, 2 to 4, 3 to 4)

This is also the only late policy for assignments. Unsubmitted assignments are
initially given a **0**, and can get a maximum of **2** points on resubmission.

### Exams

Exams will use the testing facility in [AP&M
B349](https://map.concept3d.com/?id=1005#!m/167186?share), which is a computer
lab. You will schedule your exam at a time that's convenient for you in the
given exam week, and you will go to that lab and check in for your exam at the
time you picked. The exam will be proctored by staff from the [Triton Testing
Center](https://tritontesting.ucsd.edu/) (not by the course staff from this
course). No study aids or devices are allowed to be used in the testing center.
You will need only a photo ID and something to write with (scratch paper is
available on request).

The Triton Testing Center has shared a [document of rules and tips](./images/Helpful_Tips_CBTF.pdf) for using the testing center.

The exams will be administered through
[PrairieLearn](https://www.prairielearn.com/about); we will give you practice
exams and exercises so you can get used to the format we'll use before you take
the first one. The exams will have a mix of questions; they will typically
include some that involve programming and interacting with a terminal.

There are three exams during the quarter in weeks 3, 6, and 9. On each you'll
get a score from 0-4.

We don't have a traditionally-scheduled final exam for this course (you can
ignore the block provided in Webreg). Instead, in final exam week, you'll have the
opportunity to retake exams from during the quarter to improve your score **up
to a 4**, regardless of the score on the first attempt. The retakes may be
different than the original exam, but will test the same learning outcomes. This
is also the only make-up option for missed exams during the quarter: if you miss
an exam for any reason it will be scored as 0, and you can use one of your
retake opportunities on that exam.

Exams during the quarter are all 45m long, the make-up slot is 2h long and gives
the opportunity to make up any or all 3 of the in-quarter exams.

## Grading

Each component of the course has a minimum achievement level to get an A, B, or
C in the course. You must reach that achievement level in _all_ of the
categories to get an A, B, or C.

- **A** achievement:
  - ≥34/40 lab points
  - ≥16/20 assignment points
  - ≥10/12 exam points
- **B** achievement:
  - 30-33 lab points
  - 13-15 assignment points
  - 8-9 exam points
- **C** achievement:
  - 24-29 lab points
  - 10-12 assignment points
  - 6-7 exam points

**Problem sets**: Problem set performance will determine pluses and minuses. We don't publish
an exact number for these in advance, but it's consistent across the class.

Some general examples: if you complete all the problem sets completely, correctly, and on time, you'll get a `+` modifier. If you submit no problem sets on time or don't get _any of them_ done completely or correctly, you will get a `-` modifier.

## Policies

Individual assignments describe policies specific to the assignment. Some
general policies for the course are here.

### Assignments and Academic Integrity

You can use code that we provide or that your group develops in lab as part of
your assignment. If you use code that you developed with other students (whether
in lab or outside it), got from Piazza, or got from the internet, say which
students you worked with and a sentence or two about what you did together in
`CREDITS.txt`. All of the _writing_ in assignments (e.g. in open-ended written
questions) must be your own.

You **can** use an AI assistant like ChatGPT or Copilot to help you author
assignments in this class. If you do, you are **required** to include in
`CREDITS.txt`:

- The prompts you gave to the AI chat, or the context in which you used Copilot
  autocomplete
- What its output was and how you changed the output after it was produced (if
  at all)

This helps us _all_ learn how these new, powerful, and little-understood tools
work (and don't).

If you don't include a `CREDITS.txt` and it's clear you included code from
others or from an AI tool, you may lose credit or get a 0 on the assignment, and
repeated or severe violations can be escalated to reports of academic integrity
violations.

### Exams and Academic Integrity

Problem sets are the best preparation for the exams. You're free to collaborate
with others on preparing for the exam, trying things out beforehand, and so on.

You **cannot** share details of _your_ exam with others until after you receive
your grade for it. You **cannot** communicate with anyone during the exam.

### Problem Sets and Academic Integrity

You can work on problem sets with other students.

## FAQ/AFQ (Anticipated Frequent Questions)

**Can I attend a lab section other than the one I'm enrolled in?**

No, please do not try to do this. The lab sections have limited seating and are full. We cannot accommodate switching.

**How can I switch sections?**

You have to drop and re-add (which may involve getting [back on] the waitlist). Sorry.

**Can I leave lab early if I'm done or have a conflict?**

The labs are designed to not be things you can “finish”. Labs have plenty of extension and exploration activities at the end for you to try out, discuss, and help one another with. Co-located time with other folks learning the same things is precious and what courses are for. Also, if you need an extrinsic motivation, you won't get credit for participation if you don't stay, and participate, the whole time. We can often accommodate one-off exceptions – if you have a particular day where you need to leave early, it's a good idea to be extra-engaged in your participation so your lab leader can give you participation credit before you leave.

**Do I have to come to lab?**

Yes, see grading above.

**What should I do if I'm on the waitlist?**

Attend and complete all the work required while waitlisted (this is consistent with CSE policy).

**I missed lab, what should I do?**

The lab page will have instructions on how to submit the make-up, which can get you 1 (of 4 possible) points.

**I missed a problem set deadline, what should I do?**

You can submit it late until the end of the quarter. Generally we allow lots
(think like 1/3 to 1/2) of the psets to be late without it impacting your grade.
They are there to give you focused practice and to prepare you for the exams and
the assignments.

**I missed an assignment deadline, what should I do?**

Some time after each assignment deadline (usually around 2 weeks) there is a
late/resubmission deadline. You can resubmit then. See the assignment section
above for grading details about resubmissions.

**I missed a assignment resubmission deadline, what should I do?**

You cannot get an extension on assignment resubmissions; we cannot support
multiple late deadlines and still grade all the coursework on time.

**I missed my exam time, what should I do?**

Stay tuned for announcements about scheduling make-ups in final exam week.

**Where is the financial aid survey?**

We do this for you; as long as you submit a quiz or do a lab participation in
the first two weeks, we will mark you as commencing academic activity.

**When are the midterms scheduled?**

The midterms will be flexibly scheduled during the quarter using a testing
center. More details will come; you will need to set aside some outside-of-class
time to do them, but there is not a specific class-wide time you have to put on
your calendar.

**I have a conflict with the final exam time, what can I do?**

The final exam will also be flexibly scheduled during final exam week using the testing
center.
