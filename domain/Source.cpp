#include "Source.h"


Xori::Domain::Source::Source(QObject* parent) :
        Source(-1, QUrl(), QString(), parent) {
}


Xori::Domain::Source::Source(qlonglong id,
                             const QUrl& url,
                             const QString& fileName,
                             QObject* parent) :

        QObject(parent), id(id), url(url), fileName(fileName) {
}


Xori::Domain::Source::Source(qlonglong id, const QUrl &url, QObject* parent) :
        QObject(parent) {

    this->id = id;
    this->url = url;
    fileName = fetchFileNameFromUrl();
}


Xori::Domain::Source::Source(const Source& source) :
        Source(source.id, source.url, source.fileName, source.parent()) {
}


Xori::Domain::Source::~Source() {
}


Xori::Domain::Source& Xori::Domain::Source::operator =(const Source& source) {
    id = source.id;
    url = source.url;
    fileName = source.fileName;

    setParent(source.parent());

    return *this;
}


qlonglong Xori::Domain::Source::getId() const {
    return id;
}


QUrl Xori::Domain::Source::getUrl() const {
    return url;
}


QString Xori::Domain::Source::getFileName() const {
    return fileName;
}


void Xori::Domain::Source::setId(qlonglong id) {
    this->id = id;
}


void Xori::Domain::Source::setUrl(const QUrl& url) {
    this->url = url;
}


void Xori::Domain::Source::setFileName(const QString& fileName) {
    this->fileName = fileName;
}


QString Xori::Domain::Source::fetchFileNameFromUrl() const {
    return url.toString().split("/").last();
}
