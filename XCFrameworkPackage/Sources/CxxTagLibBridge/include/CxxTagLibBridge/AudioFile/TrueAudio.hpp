
#import <CxxTagLibBridge/AbstractAudioFile.hpp>
#import <taglib/trueaudiofile.h>

namespace AudioFile {
    struct TrueAudio final: public AbstractAudioFile<TagLib::TrueAudio::File> {
    public:
        using AbstractAudioFile::AbstractAudioFile;
    protected:
        using FileType = TagLib::TrueAudio::File;

        void read_metadata_implementation(
            FileType &file,
            AudioMetadata *metadata,
            const MetadataOverlayStrategy overlayStrategy
        ) const {
            if (file.hasID3v1Tag()) {
                metadata->overlay(AudioMetadata::read_from_ID3v1_tag(file.ID3v1Tag()), overlayStrategy);
            }
            if (file.hasID3v2Tag()) {
                metadata->overlay(AudioMetadata::read_from_ID3v2_tag(file.ID3v2Tag()), overlayStrategy);
            }
        }

        void write_metadata_implementation(FileType &file, AudioMetadata *metadata) const {
            if (file.hasID3v1Tag()) {
                metadata->write_to_ID3v1_tag(file.ID3v1Tag());
            }
            metadata->write_to_ID3v2_tag(file.ID3v2Tag(true));
        }
    };
}
