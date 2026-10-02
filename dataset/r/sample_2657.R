library(stringr)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(text = "character", vocabulary = "list", vector = "list"),
  methods = list(
    initialize = function(text) {
      text <<- tolower(text)
      vocabulary <<- unique(unlist(str_split(text, "\\s+")))
      vector <<- list()
    },
    create_vector = function() {
      for (word in vocabulary) {
        vector[word] <<- sum(str_count(text, word))
      }
    }
  )
)

Sequence <- setRefClass("Sequence",
  fields = list(vectorizer = "Vectorizer", sequence = "list"),
  methods = list(
    initialize = function(vectorizer) {
      vectorizer <<- vectorizer
      sequence <<- list()
    },
    generate_sequence = function(length) {
      for (i in 1:length) {
        sequence[[i]] <<- vectorizer$vector
      }
    }
  )
)

Analyze <- setRefClass("Analyze",
  fields = list(sequence = "Sequence"),
  methods = list(
    initialize = function(sequence) {
      sequence <<- sequence
    },
    calculate_entropy = function() {
      total_words <<- sum(sapply(sequence$sequence, function(v) sum(v)))
      entropy <<- 0
      for (vector in sequence$sequence) {
        for (count in unlist(vector)) {
          probability <<- count / total_words
          entropy <<- entropy - probability * log2(probability)
        }
      }
      return(entropy)
    }
  )
)

main <- function() {
  text <- "Natural language processing vectorization involves converting text into numerical vectors"
  vectorizer <- Vectorizer$new(text)
  vectorizer$create_vector()
  sequence <- Sequence$new(vectorizer)
  sequence$generate_sequence(5)
  analyze <- Analyze$new(sequence)
  entropy <- analyze$calculate_entropy()
  print(paste("Entropy:", entropy))
}

main()