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

And this should work... let's try it now. From their `src/makefile`, it seems alchemy has the following dependencies:

```makefile
GPP=g++
FLEX=flex
BISON=bison
```

It seems I have all these dependencies locally on my mac already (yay):

```zsh
$ which g++
/usr/bin/g++
$ which flex
/usr/bin/flex
$ which bison
/usr/bin/bison
```

Running `make depend` appears to be successful. Against my expectations (of someone coming from a enterprise development world), the `make depend` command modifies in-place the `src/makefile` and "enables" the `make` command.

For reference, the `make depend` looks like:

```makefile
depend:
  @echo 'updating the dependencies for:'
  @echo '    ' $(CPPFILES)
  @( \
  < $(MF) sed -n '1,/^###.*SUDDEN DEATH/p'; \
      echo '#' ; \
      echo '# dependencies generated on: ' `date` ; \
      echo '#' ; \
      for i in $(CPPFILES); do \
          echo -n "$(OBJDIR)/" ; \
          $(GPP) -MM $(CFLAGS) $$i ; \
          echo; \
      done \
  ) > $(MF).new
  @mv $(MF) $(MF).last
  @mv $(MF).new $(MF)
```

But, upon using the newly generated `make` command, I get the following error:

```zsh
➜  src git:(master) ✗ make
makefile:402: *** missing separator.  Stop.
```

The error apparently is the result of improper tab v. space usage as per [this stackoverflow question][10]. This is ultimately because the `echo` program on the mac refuses to properly accept the `-n` flag, instead it merely echoes it. Slightly rewriting their `depend` instruction's for loop to the following fixes it:

```bash
for i in $(CPPFILES); do \
  KILL_ME=`$(GPP) -MM $$CFLAGS $$i`; \
  echo "$(OBJDIR)/" $$KILL_ME; \
  echo; \
done \
```

Running it, however, it seems we now have some issues regarding dependency issues. Notably, any header file (e.g. `array.h`) that doesn't have matching `cpp` file seems to crash. I'm not sure what causes this

As it turns out, it was because `$$CFLAGS` evaluated to null and thus all my `#include`s were missing; this is fixed by changing to:

```makefile
debug:
	for i in $(CPPFILES); do \
		KILL_ME=`$(GPP) -MM ${CFLAGS} $$i`; \
		echo "$(OBJDIR)/$$KILL_ME"; \
		echo; \
	done
```

>note: Can I just say, either make and shell is hard, or I'm literally retarded 😭

Anyway, after all this, I'm *finally* able to `make depend`

However, upon running `make` when the configured makefile, everything breaks due to c++ type checks (pls kill me)

Things to try next time

- [ ] mac-osx install [issues][14] may be due to inappropriate gcc version (needs 4.9)
- [ ] I should consult the install instructions on their [site][13]

# Appendix

## A1 - Thoughts on Alchemy

I originally heard about Markov Logic Networks and alchemy by listening to [The Master Algorithm][2] on audible. A bit of investigation into the source code and the [University of Washington alchemy project page][1] suggests the following:

- Professor Domingos seems to have had the idea for MLNs sometime in 2009
- [The Master Algorithm][2] seems to have been published in 2015
- I have no idea how actively maintained this idea is
  - If my other projects in open source (including and perhaps especially my own) are any indication, there is no guarantee that MLNs panned out as the true correct idea

So a natural question to ask is that, today, in late 2018 (December 27), are MLNs and alchemy a worthy idea to learn?

Of course, not knowing what I don't know, I can't make a "good" judgement on this issue at this time. Therefore, given how little I know of this subject, any start as good as another, so I'm just going to dive head-first into this. If I turn out to be mistaken, I could always jump onto more main-stream techniques like [tensorflow][3] some time later

## A2 - On Programming Language Tools

Alchemy (as well as tons of other "comp-sci" projects) seem to depend a lot on linux tools such as:

- [flex][8]
  - A lexer on linux systems
- [bison][9]
  - A parser generator

As someone who entered into development through web-programming instead of computer science, I obviously don't have the background to properly know how to use these tools. I should endeavor to fix this and brush up on my knowledge of programming languages and the like

## A3 - A Quick and Dirty Guide to Makefiles

Q: What's the deal with spaces and tabs in makefiles?

A: `make`, the ancestor of more sensible compilation systems like `npm`, `rake`, `mix`, `cargo`, or `go`, is a bit of hassel to work with. Here are some eccentricities:

As per [this stack article][10], `Makefile`s require `\t` tabs in order to work properly, this means modifying my `.editorconfig` to also include the following

```text
[{Makefile,makefile,makefile.*,**.mk}]
indent_style = tab
```

>Note: read about [editorconfig here][11]

Q: What is the `@` stuff I see in front of certain commands like:
```makefile
depend:
  @echo "something"
```
and what's the difference versus if I don't put in the `@` in front of the `echo` command?

A: Apparently the `@` suppresses printing of the command text it self; consider the examples:

```sh
➜  alchemy-2 git:(master) ✗ make depend
Death 2 makefiles
➜  alchemy-2 git:(master) ✗ make depend
echo "Death 2 makefiles"
Death 2 makefiles
```

When I put in the `@echo`, we suppress printing our echo instructions

## A4 - A Quick and Dirty Overview of g++ and sh

C, C++, and their ilk are all (typically) compiled with `g++` on unix systems, and alchemy project is no different. One thing to note from their make file is this line:

```Makefile
depend:
  # other stuff
  $(GPP) -MM $(CFLAGS) $$i ; \`
```

According to the [gcc preprocessor docs][12], it seems the `-MM` flag generates dependency lists for make files (but exclude system level dependencies)

Another thing to note is the following inputs and outputs:

```makefile
debug1:
	KILL_ME="Oh god"; \
	echo $KILL_ME; \
	echo "$KILL_ME"; \
	echo ${KILL_ME}; \
	echo $$KILL_ME; \
	echo `KILL_ME`; \
```

```zsh
➜  src git:(master) ✗ make debug1
KILL_ME="Oh god"; \
	echo ILL_ME; \
	echo "ILL_ME"; \
	echo ; \
	echo $KILL_ME; \
	echo `KILL_ME`; \

ILL_ME
ILL_ME

Oh god
/bin/sh: KILL_ME: command not found
```

We have the following correspondence
- ```echo $KILL_ME; \``` => ```ILL_ME```
- ```echo "$KILL_ME"; \``` => ```ILL_ME```
- ```echo ${KILL_ME}; \``` => ``` # empty space ```
- ```echo $$KILL_ME; \``` => ```Oh god```
- ```echo `KILL_ME`; \``` => ```/bin/sh: KILL_ME: command not found```

I note the following:

- `$` is some sort of `quote` operator
- When coupled with a letter or number (e.g. `$1`) it refers to something
- We need to "double up" on the `$` in order to get them to properly refer to the variable we have in mind; this is a natural consequence when we have data being a part our program... but this is a defining characteristic of a high-level LISP-like language

Finally, for reference, what finally got this to stuff output what I wanted was the following:

```makefile
debug:
	for i in $(CPPFILES); do \
		KILL_ME=`$(GPP) -MM $$CFLAGS $$i`; \
		echo "$(OBJDIR)/"; \
		echo $$KILL_ME; \
	done
```

# References

As usual, see the raw souce version of this page to view the entire bibliography in full

[1]: <https://alchemy.cs.washington.edu/> "Alchemy Welcome Page"
[2]: <https://www.amazon.com/Master-Algorithm-Ultimate-Learning-Machine/dp/1501299387> "The Master Algorithm by Pedro Domingos on Amazon"
[3]: <https://www.tensorflow.org/> "TensorFlow landing page"
[4]: <https://code.google.com/archive/p/alchemy-2/downloads> "Alchemy 2 Download Page"
[5]: <https://www.barnesandnoble.com/w/markov-logic-pedro-domingos/1017509868?ean=9781598296921&st=PLA&sid=BNB_New+Core+Shopping+Books&sourceId=PLAGoNA&dpid=tdtve346c&2sid=Google_c&gclid=Cj0KCQiAjZLhBRCAARIsAFHWpbEOJyMAwDIVsm3ogNTzvY2PlaWdm7m5PAlSeuIJ9KZEUKZcCYxTsUEaAlVsEALw_wcB> "Barnes & Noble Product Page for Markov Logic: An Interface Layer for AI"
[6]: <https://homes.cs.washington.edu/~pedrod/803/> "Course Page for the Markov Logic class from 2008"
[7]: <http://alchemy.cs.washington.edu/tutorial/tutorial.pdf> "Alchemy Tutorial from Lecture 6 of Domingos's 2008 class"
[8]: <https://www.gnu.org/software/flex/> "Flex - a Lexer for Linux"
[9]: <https://www.gnu.org/software/bison/> "Bison - a Parser Generator for Linux"
[10]: <https://stackoverflow.com/questions/16931770/makefile4-missing-separator-stop> "Stackoverflow - Makefile Missing Separator Stop"
[11]: <https://editorconfig.org/> "EditorConfig"
[12]: <https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html> "g++ preprocess options"
[13]: <http://alchemy.cs.washington.edu/requirements.html> "Alchemy Installation Requirements"
[14]: <https://code.google.com/archive/p/alchemy-2/issues/13> "MacOSX Installation Issue from Google Code"
