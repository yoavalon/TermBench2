HashFunction <- setRefClass("HashFunction",
    fields = list(
        data = "raw",
        hash_value = "integer"
    ),
    methods = list(
        initialize = function(data) {
            .self$data <- data
            .self$hash_value <- 0
            .self
        },
        update = function() {
            for (byte in as.integer(rawToBits(.self$data))) {
                .self$hash_value <- (.self$hash_value * 33) %xor% byte
            }
            .self
        },
        digest = function() {
            .self$hash_value
        }
    )
)

CipherSimulator <- setRefClass("CipherSimulator",
    fields = list(
        key = "raw",
        data = "raw",
        encrypted_data = "raw"
    ),
    methods = list(
        initialize = function(key, data) {
            .self$key <- key
            .self$data <- data
            .self$encrypted_data <- rep(0, length(data))
            .self
        },
        encrypt = function(index = 0) {
            if (index >= length(.self$data)) {
                return(.self)
            }
            .self$encrypted_data[index + 1] <- .self$data[index + 1] %xor% .self$key[(index %% length(.self$key)) + 1]
            .self$encrypt(index + 1)
            .self
        },
        get_encrypted_data = function() {
            .self$encrypted_data
        }
    )
)

main <- function() {
    original_data <- charToRaw("Hello, world!")
    hash_function <- HashFunction$new(original_data)
    hash_function$update()
    hash_value <- hash_function$digest()
    key <- charToRaw("secret")
    cipher_simulator <- CipherSimulator$new(key, original_data)
    cipher_simulator$encrypt()
    encrypted_data <- cipher_simulator$get_encrypted_data()
    cat("Hash Value: ", hash_value, "\n")
    cat("Encrypted Data: ", paste(as.character(encrypted_data), collapse = " "), "\n")
}

main()