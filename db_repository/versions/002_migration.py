from sqlalchemy import *
from migrate import *


from migrate.changeset import schema
pre_meta = MetaData()
post_meta = MetaData()
led_colors = Table('led_colors', post_meta,
    Column('title', String),
    Column('id', Integer, primary_key=True, nullable=False),
    Column('Red', Integer),
    Column('Blue', Integer),
    Column('Green', Integer),
    Column('timestamp', DateTime),
)


def upgrade(migrate_engine):
    # Upgrade operations go here. Don't create your own engine; bind
    # migrate_engine to your metadata
    pre_meta.bind = migrate_engine
    post_meta.bind = migrate_engine
    post_meta.tables['led_colors'].columns['timestamp'].create()


def downgrade(migrate_engine):
    # Operations to reverse the above upgrade go here.
    pre_meta.bind = migrate_engine
    post_meta.bind = migrate_engine
    post_meta.tables['led_colors'].columns['timestamp'].drop()
