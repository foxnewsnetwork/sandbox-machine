# Getting Started with Alchemy

[Alchemy][1] is a reference implementation of the so-called "Markov Logic Network" created and supported by Professor Pedro Domingos and his students at the University of Washington.

In any case, this entry will have the following sections:

- [Initial Setup](#initial-setup)
- [Appendix](#a1-thoughts-on-alchemy)

The plan is probably to attempt to following along with the University of Washington's Fall 08 [Markov Logic class][6], notably here in this entry, I want to at least get through the [initial setup pdf][7]

## Initial Setup

The source code for [alchemy-2][4] can be downloaded from code repo page on Google Code. According to [appendix section in the Markov Logic Network book][5], users of alchemy must apparently download, make, and install the code directly on their own machines.

To make things easier for me now (and in the future), their entire code base lives under [packages/alchemy-2](../packages/alchemy-2).

According to the installation docs, installation should be as easy as:

- Go into `alchemy/src`
- Run `make depend`
- Run `make`

And this should work... let's try it now

# Appendix

## A1 - Thoughts on Alchemy

I originally heard about Markov Logic Networks and alchemy by listening to [The Master Algorithm][2] on audible. A bit of investigation into the source code and the [University of Washington alchemy project page][1] suggests the following:

- Professor Domingos seems to have had the idea for MLNs sometime in 2009
- [The Master Algorithm][2] seems to have been published in 2015
- I have no idea how actively maintained this idea is
  - If my other projects in open source (including and perhaps especially my own) are any indication, there is no guarantee that MLNs panned out as the true correct idea

So a natural question to ask is that, today, in late 2018 (December 27), are MLNs and alchemy a worthy idea to learn?

Of course, not knowing what I don't know, I can't make a "good" judgement on this issue at this time. Therefore, given how little I know of this subject, any start as good as another, so I'm just going to dive head-first into this. If I turn out to be mistaken, I could always jump onto more main-stream techniques like [tensorflow][3] some time later


# References

As usual, see the raw souce version of this page to view the entire bibliography in full

[1]: <https://alchemy.cs.washington.edu/> "Alchemy Welcome Page"
[2]: <https://www.amazon.com/Master-Algorithm-Ultimate-Learning-Machine/dp/1501299387> "The Master Algorithm by Pedro Domingos on Amazon"
[3]: <https://www.tensorflow.org/> "TensorFlow landing page"
[4]: <https://code.google.com/archive/p/alchemy-2/downloads> "Alchemy 2 Download Page"
[5]: <https://www.barnesandnoble.com/w/markov-logic-pedro-domingos/1017509868?ean=9781598296921&st=PLA&sid=BNB_New+Core+Shopping+Books&sourceId=PLAGoNA&dpid=tdtve346c&2sid=Google_c&gclid=Cj0KCQiAjZLhBRCAARIsAFHWpbEOJyMAwDIVsm3ogNTzvY2PlaWdm7m5PAlSeuIJ9KZEUKZcCYxTsUEaAlVsEALw_wcB> "Barnes & Noble Product Page for Markov Logic: An Interface Layer for AI"
[6]: <https://homes.cs.washington.edu/~pedrod/803/> "Course Page for the Markov Logic class from 2008"
[7]: <http://alchemy.cs.washington.edu/tutorial/tutorial.pdf> "Alchemy Tutorial from Lecture 6 of Domingos's 2008 class"