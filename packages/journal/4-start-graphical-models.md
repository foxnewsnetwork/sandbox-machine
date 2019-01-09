# Introduction to Graphical Probabilistic Models

After the rather blind foray into machine learning by first trying to use alchemy in my [previous journal entry](./3-using-alchemy.md), I now have a list of things I know I don't know:

- Q: What are "groundings"
- Q: How do MLNs relate to Markov Random Fields?
- Q: How do MRFs relate to Bayesnian networks?
- Q: What about other markov models?

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

I'm currently trying to use [pipenv][2] and [python-project-template][3] to get up and running, however, am currently running into trouble getting [paver][4] to run. Will need to diagnose. Glancing at their website, paver functionality seems to be superceded by pipenv - likely I will need TODO:

- [ ] bake in another testing framework
- [ ] remove paver

# References

[1]: <https://getpocket.com/explore/item/the-secret-algorithm-behind-learning> "The Secret PsuedoCode Behind Learning"
[2]: <https://github.com/pypa/pipenv> "Pipenv - package manager for python"
[3]: <https://github.com/seanfisk/python-project-template> "Python Project Template"
[4]: <https://github.com/paver/paver> "Python Paver"
