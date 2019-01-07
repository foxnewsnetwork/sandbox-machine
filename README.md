# Machine Learning Sandbox

Machine learning, AI, and probability form a side of programming / CS that I'm currently unfamilar with. To fix this, I will endeavor to learn the tools, techniques, etc., in this field. As per usual, I will document my learning process via journals and associated code in this repo

## Goals

Get comfortable with machine learning, probability, statistics, and ultimately apply that knowledge to automate everything I currently do. Obviously, this is going to be a long running task that will take truly years.

### 1 - Setup Alchemy Locally

Markov Logic Networks, as according to professor Pedro Domingos, is a good entry point for the universal learner; I will start my journey to machine learning by running through his tutorials on it. See [full journal entry here](./packages/journal/1-alchemy-setup.md)

TODOs

- [ ] Try doing this on a linux box
- [ ] Figure out why compilation fails on macOS

### 2 - Start to Learn Jison

Although I have no real hard evidence, my inner support vector machine is drawing an analogy between machine learning and language construction. Now, I know next to nothing about how to construct a language, so I want to fix this by learning how to use bison to construct a language. See [first journal entry here](./packages/journal/2-start-jison.md)

### 3 - First Steps in Using Alchemy

After an extremely painful slog through `make` and `c++`, I finally managed to build alchemy, now to actually use it! See the [journal entry here](./packages/journal/3-using-alchemy.md)

### 4 - First Steps in Graphical Models

After a bit of using alchemy and research, it seems that Domingos's Markov Logic Networks are instances of Markov Random Fields except where nodes contain first order logic formula instead of states (or measurables in the case of hidden markov).

However, I'm currently unfamiliar with markov random fields (or really the entire world of graphical probabilistic models), so I will endeavor to start learning it. See the [journal entry here](./packages/journal/4-start-graphical-models.md)

### ? - Learn Rust Concepts

[Rust](https://www.rust-lang.org/) ships with the following 3 interesting concepts:

- [ownership](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html)
- [traits](https://doc.rust-lang.org/book/ch10-02-traits.html)
- [lifetimes](https://doc.rust-lang.org/book/ch10-03-lifetime-syntax.html)

In the process of learning the meta-language of bison / yacc, I should endeavor to also learn these new memory related concepts and try to implement them. Ideally, I try to figure out how the ideas of ownership and stuff contrasts with [Q#](https://docs.microsoft.com/en-us/quantum/language/type-model?view=qsharp-preview) and quantum ideas of reversibility (aka unitarity) and entanglement

### ? - Parse and Setup Video Streams

One obvious application of ML is to process images and streams of images (aka video) for the purposes of automating game-playing or web surfing. I would like to use something like [libsdl](https://www.libsdl.org/) to stream-capture and process in hopes of furthering the ultimate goal to build a machine that can do my job

### ? - On The Missing Theory to Tie Together Everything

>note: Math rendering syntax provided via [mathjax][1] using [latex syntax][2]

We know that:

- Money represents usable time (perhaps a more sensible name would be something like "work hour", or merely labor)
```math
money = time
```
- All (interesting) resources $r_n$ can be transmuted from some base resource $r_0$ (e.g. water, sunlight, etc.); that is, a sensible ordering for the set of "interesting resources" is to order them by amount of time required to transmute using knowledge $K_0$
```math
r_n = K_0(t_n)
```
- Notice that $K_0$ depends on $r_0$ 
- We know that work time $t_n$ decreases with lifespan at some rate (or perhaps it can increase if one isn't in a awful job)

>conjecture: $K \subset r$ that is, knowledge *is* a resource (that is, it's physical)

Anyway, the idea I'm trying to work out here is that while money is a good measure of societal fungible time, there should also exist another metric that measures growth of knowledge. Evolutionarily, the strongest most survivable species might be the one that optimizes best the tradeoff between time and knowledge

TODOs

- [ ] Figure out how this has to do with ye olde explore v. exploit tradeoff
- [ ] Workout what my conjecture about knowledge being a subset of resources even means
- [ ] Figure out what all this has to do with learning

# References

See the raw page for the reference list

[1]: <https://www.mathjax.org/> "MathJax Landing Site"
[2]: <https://en.wikibooks.org/wiki/LaTeX/Mathematics> "LaTex syntax guide"
