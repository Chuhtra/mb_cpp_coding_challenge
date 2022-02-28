# Simple Intent Recognizer (CLI)

This is a simple CLI app for basic intent recognition. It is created as a C++ coding challenge.

## Build & Other information

- This app can be built using `mkdir build && cd build && cmake .. && make`.
- It is tested using Linux and the `g++ 11.2.0` compiler.
- It includes unit tests using the [Google Test](https://google.github.io/googletest/) suit.

## Thoughts on expendability

**Object-oriented architecture** 

The app is intentionally modelling Intents as objects, in order to set the foundation for future extensions regarding what an Intent represents and supports in terms of storage and manipulation. Similarly, for IntentProcessors, the objects that include the management and preprocessing of user input before it is assigned to an Intent object, a class construct is used. This way, new functionality can later be added as a member attribute or a function that abstracts internal implementation details. 

**Generic Input Handling** 
  
This app is completely oblivious about sentence structure or semantics with regard to the input. Since the service revolves around the recognition of specific keywords (e.g. notions of interest like the weather or facts, geographic locations like cities or countries etc.), a minimal and lightweight (and thus error-free) approach leads to the use of a mapping, instead of a more elaborate natural language parser. This way, we provide to the application the needed information resource to handle and identify information (topics) of interest. This allows easy expendability by editing the provided mapping, adding or replacing available keywords and corresponding tags.

**Replacing mappings with other resources** 

Of course, while a defined mapping makes sense in this setting, it may not do so in greater scale. In that case it would be easy to transfer the mapping to an external file (e.g. JSON, CSV or other), or an external resource like a complementary database or the cloud. This way, updating or replacing the information resource can become more streamlined.

**AI can increase potential**

My initial approach for this application was to include the use of an external library (e.g. [spacy-c++](https://spacy.io/universe/project/spacy-cpp), [Freeling](https://nlp.lsi.upc.edu/freeling/node/1), [MITIE](https://github.com/mit-nlp/MITIE)) to derive the user's provided intent in the most dynamic way possible. This approach would begin with a Part-of-Speech (POS) tagging step in order to clean the topics of interest (nouns) from the rest of the sentence. Afterwards, further tagging the filtered information in a Named Entity Recognition (NER) setting could easily provide informative tags regarding possible topics of importance (e.g. identifying Paris as a city or a human's name as a Contact, before searching either, in a secondary information resource among the several available ones; guided by the rest of the collected information). 

A curated resource of available information still remains a requirement, be it in the form of a structured JSON file, a Knowledge Graph, a database etc. This fact is the main reason I ended up only using a mapping, representing this information resource. For example, an NER system can identify Paris as a geographical entity, but to identify it as a city, a secondary information retrieval step is needed. The POS tagging and NER step can only enable a quicker flow of information when the available resource is too large or scattered.