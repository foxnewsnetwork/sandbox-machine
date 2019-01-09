# Introduction to Graphical Probabilistic Models

After the rather blind foray into machine learning by first trying to use alchemy in my [previous journal entry](./3-using-alchemy.md), I now have a list of things I know I don't know:

- Q: What are "groundings"
- Q: How do MLNs relate to Markov Random Fields?
- Q: How do MRFs relate to Bayesian networks?
- Q: What about other Markov models?

The purpose of this journal entry is to attempt to understand what these things are by attempting to implement them all on my own / going through documentation.

See [here](../intgraph)

# Appendix

## A1 - Feynman on the Process of Learning

Firefox recently recommended [this article][1] on "learning" where the author explains "Feynman's Technique" on learning. Paraphrasing, it is:

- "Demystify": filter and cluster new data in my own brain
- "Simplify": reduce size of new clusters as much as possible
- "Teach to a child": or alternatively a computer; the idea here is to faithfully "replicate" the newly learned meme in another brain such that they can repeat the process

There seems to be some sort of odd parallel here between Feynman's learning technique and the reproductive cycle of memes (and species, I suppose)

## A2 - Setting up a Python Project

I'm currently trying to use [pipenv][2] and [python-project-template][3] to get up and running, however, am currently running into trouble getting [paver][4] to run. Will need to diagnose. Glancing at their website, paver functionality seems to be super-ceded by pipenv - likely I will need TODO:

- [ ] bake in another testing framework
- [ ] remove paver

## A3 - Unrelated Notes on Judea Pearl's Book of Why

[Judea Pearl's Book of Why][6] (and accompanying [PDF][9]) discusses something totally new for me: a graphical model for causality that he calls "do-calculus". I have no idea what this thing is, so I will need to do a future journal entry that goes into further details. I think it'll serve me well to go through the [causal model][7] stuff on Stanford Plato

An interesting side-note on Judea Pearl, according to his [wiki page][8], apparently he also popularized / invented the Bayesian Network - quite an accomplished fellow!

## A4 - Why I Stopped Reading Joe Dispenza's Evolving Your Brain

[Joe Dispenza's Evolving Your Brain][5] is hard to slog through for the following reasons:

- focus on mysticism
- constantly reinforces the reader with snake-oil mantras
  - "You have the power"
  - "You are a miracle"
  - "You ..."
  - Stop trying to get me to "feel"
- lack of focus on objective facts or theories
- Uses the Copenhagen interpretation of quantum mechanics as a justification for the primacy of consciousness
  - Clearly obsessed with duality despite the fact he decries it upfront

# References

[1]: <https://getpocket.com/explore/item/the-secret-algorithm-behind-learning> "The Secret PseudoCode Behind Learning"
[2]: <https://github.com/pypa/pipenv> "Pipenv - package manager for python"
[3]: <https://github.com/seanfisk/python-project-template> "Python Project Template"
[4]: <https://github.com/paver/paver> "Python Paver"
[5]: <https://www.audible.com/pd/Evolve-Your-Brain-Audiobook/B01NANC6PV> "Evolve Your Brain on Audible"
[6]: <https://www.audible.com/pd/The-Book-of-Why-Audiobook/B07CYGJDJ8> "Book of Why on Audible"
[7]: <https://plato.stanford.edu/entries/causal-models/index.html> "Causal Models from Stanford Philosophy"
[8]: <https://en.wikipedia.org/wiki/Judea_Pearl> "Judea Pearl on Wikipedia"
[9]: <http://download.audible.com/product_related_docs/BK_BRLL_010665.pdf> "Accompanying PDF to the Book of Why on Audible"
