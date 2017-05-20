#ifndef XORI_DOMAIN_SOURCE_H
#define XORI_DOMAIN_SOURCE_H


#include "Xori.h"

#include <QObject>
#include <QUrl>


class Xori::Domain::Source : public QObject {

    public:
        Source(QObject* parent = 0);

        Source(qlonglong id,
               const QUrl& url,
               const QString& fileName,
               QObject* parent = 0);

        Source(const Source& source);
        ~Source();

        Source& operator =(const Source& source);

        qlonglong getId() const;
        QUrl getUrl() const;
        QString getFileName() const;

        void setId(qlonglong id);
        void setUrl(const QUrl& url);
        void setFileName(const QString& fileName);


    private:
        qlonglong id;
        QUrl url;
        QString fileName;
};


#endif // XORI_DOMAIN_SOURCE_H
