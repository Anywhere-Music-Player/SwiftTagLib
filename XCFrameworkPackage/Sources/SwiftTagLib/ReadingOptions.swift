
@_implementationOnly import CxxTagLibBridge

public extension AudioFile.Metadata {
    /// Defines how `AudioFile.Mmetadata` is read.
    struct ReadingOptions: OptionSet, Hashable, Equatable, CxxRepresentable, CustomStringConvertible {
        /// Skip the images when reading metadata.
        public static var skipImages: Self { .init(rawValue: 1 << 0) }

        public let rawValue: UInt32

        public init(rawValue: UInt32) {
            self.rawValue = rawValue
        }

        init(cxxRepresentation: MetadataReadingOptions) {
            self.init(rawValue: cxxRepresentation.rawValue)
        }

        var cxxRepresentation: MetadataReadingOptions {
            MetadataReadingOptions(rawValue: rawValue)
        }

        public var description: String {
            var descriptions: [String] = []
            if contains(.skipImages) {
                descriptions.append("skipImages")
            }
            return "ReadOptions(" + descriptions.joined(separator: ", ") + ")"
        }
    }
}
