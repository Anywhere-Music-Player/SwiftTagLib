
#import "AbstractAudioFile.hpp"
#import <taglib/apefile.h>

namespace AudioFile {
    struct MonkeyAudio final: public AbstractAudioFile<TagLib::APE::File> {
    public:
        using AbstractAudioFile::AbstractAudioFile;
    protected:
        using FileType = TagLib::APE::File;

        void read_metadata_implementation(FileType &file, AudioMetadata *metadata) const {
            if (file.hasID3v1Tag()) {
                metadata->overlay(AudioMetadata::read_from_ID3v1_tag(file.ID3v1Tag()));
            }
            if (file.hasAPETag()) {
                metadata->overlay(AudioMetadata::read_from_APE_tag(file.APETag()));
            }
        }

        void write_metadata_implementation(FileType &file, AudioMetadata *metadata) const {
            if (file.hasID3v1Tag()) {
                metadata->write_to_ID3v1_tag(file.ID3v1Tag());
            }
            metadata->write_to_APE_tag(file.APETag(true));
        }
    };
}
