# A First Attempt at Using Alchemy

We all know there are problems with machine learning

- It doesn't converge
- It seems we adjust dials on it until it tells us what we want
- It's knowledge engineering via programming with nonsense

[xkcd sums it up well][1]

![xkcd on machine learning](https://imgs.xkcd.com/comics/machine_learning.png)

In any case, I will attempt to follow Professor Domingos's [2008 course][2]

## The Basics

We follow the pdf [first tutorial][3]. Recall from the lectures that the MLN alchemy network works something like the following:

>note: written in [flow][4]

```flow
know=>start: Initial Knowledge
evi=>start: Evidence
mln=>operation: MLN
res=>inputoutput: Prediction
cor=>operation: Correction

evi->mln->res->cor->mln
```

So a big part of this process is using `learnwts`, `learnstruct`, and `infer` to "teach" our MLN in this feedback process

I will use the [animals dataset][5] to attempt to learn a MLN

## Tutorial Basic Data

Pulling from the [basic tutorial section][6], we have a coin flip tutorial currently stored at:

- [evidence](../alchemy-2/db/tutorial/basics.db)
- [input mln](../alchemy-2/mln/tutorial/basics.mln)

We now can attempt to use the `infer` with a query

```bash
$ bin/infer -i tutorial/basics/input.mln -r tutorial/basics/query.result -e tutorial/basics/data.db -q Outcome
```

Running the above generates a `query.result` that looks like:

```
Outcome(1,2) 4.9995e-05
Outcome(1,3) 4.9995e-05
Outcome(1,4) 4.9995e-05
...
```
That is, it seems that everybody has an uniform probability distribution.

Next, I will try using `learnwts` to learn weights

```bash
$ bin/learnwts -i tutorial/basics/input.mln -o tutorial/basics/learnwts.mln -t tutorial/basics/data.db -ne Outcome
```

>note: running this stuff takes forever, it seems

- `-ne Outcome` is apparently some sort of flag to tell the system what is "not-evidence" and should therefore be learned

- the `Outcome(throw, face!)` in `input.mln` is a shorthand for the constraint that:
  - For each throw, there is exact 1 outcome
  - This boils down the logical constraint:
  ```text
  Exist f Outcome(t, f).
  Outcome(t, f) ^ f != f’ => !Outcome(t, f’).
  ```
  - Recall that `.` is a hard constraint (meaning infinite weight)
- the `Outcome(t, +f)` is equivalent to running f across its entire range 

## What This Means

The output of the `learnwts` has given me the following:

```text
//predicate declarations
Outcome(throw,face!)

// 3.17101  Outcome(t,C@face@1)
3.17101  Outcome(a1,1)

// -0.247907  Outcome(t,C@face@2)
-0.247907  Outcome(a1,2)

// -0.309268  Outcome(t,C@face@3)
-0.309268  Outcome(a1,3)

// -0.249667  Outcome(t,C@face@4)
-0.249667  Outcome(a1,4)

// -0.272887  Outcome(t,C@face@5)
-0.272887  Outcome(a1,5)

// 3.13049  Outcome(t,C@face@6)
3.13049  Outcome(a1,6)

// 0       Outcome(a1,a2!)
0       Outcome(a1,a2)
```

Which we can re-infer with the new `-ms` flag

```bash
$ bin/infer -ms -i tutorial/basics/learnwts.mln -r tutorial/basics/query.result -e tutorial/basics/empty.db -q Outcome
```

But... TODOs

- [ ] why are my generated outputs still uniform?
- [ ] what does "grounded" mean?
- [ ] how was all this generated?
- [ ] what does this mean?
- [ ] why did it take so long?
- [ ] how did it all work?


## Learning Structure

TODO:

Followed by `learnstruct` to learn the structure

```bash
$ bin/learnstruct -i tutorial/basics/learnwts.mln -o tutorial/basics/learnstruct.mln -t tutorial/basics/data.db -ne Outcome
```

# Appendix

## A1 - Animal Stuff

From the [tutorial][5], we have:

>"We have encountered two file types: .mln files and .db files. The former contains the MLN used for inference or learning, the latter contains a set of ground atoms used as training examples (when learning) or evidence (when running inference)."

A snippet from our [animal.db](../alchemy-2/db/animal.db) file, we have something like:

```text
R(Grizzly_Bear,Black)
R(Killer_Whale,Black)
```

These things are apparently called "ground atoms" (aka "training examples" and "evidence")

## A2 - Resources on Bayesian Probability

- [Maximum a Posteriori Estimates][7]

# References

[1]: <https://xkcd.com/1838/> "XKCD on machine learning"
[2]: <https://homes.cs.washington.edu/~pedrod/803/> "Course Page for the Markov Logic class from 2008"
[3]: <http://alchemy.cs.washington.edu/tutorial/tutorial.pdf> "2008 Alchemy Tutorial"
[4]: <https://shd101wyy.github.io/markdown-preview-enhanced/#/diagrams?id=flow-charts> "Flow Diagrams in Markdown"
[5]: <http://alchemy.cs.washington.edu/data/animals/> "Animal dataset"
[6]: <http://alchemy.cs.washington.edu/data/tutorial/> "Alchemy Tutorial DataSets"
[7]: <https://www.youtube.com/watch?v=kkhdIriddSI> "Tutorial on MAP estimation"
