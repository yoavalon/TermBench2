use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};

fn func() -> (String, String) {
    let a = b"secret_key";
    let b = b"data";
    let c = Sha256::digest(b).to_hex_string();
    let d = Hmac::<Sha256>::new_from_slice(a).unwrap().chain_update(b).finalize().into_bytes().to_hex_string();
    (c, d)
}

fn main() {
    func();
}

trait ToHexString {
    fn to_hex_string(&self) -> String;
}

impl ToHexString for [u8] {
    fn to_hex_string(&self) -> String {
        self.iter().map(|byte| format!("{:02x}", byte)).collect()
    }
}

impl ToHexString for <Sha256 as Digest>::OutputSize {
    fn to_hex_string(&self) -> String {
        self.iter().map(|byte| format!("{:02x}", byte)).collect()
    }
}