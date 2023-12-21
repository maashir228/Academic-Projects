
CREATE TABLE [dbo].[Employerjobs] (
    [s_no]           INT            IDENTITY (1, 1) NOT NULL,
    [ID]             NVARCHAR (50)  NULL,
    [job_name]       NCHAR (100)    NULL,
    [minimum_salary] MONEY          NULL,
    [min_hours]      NVARCHAR (MAX) NULL,
    [vacant]         BIT            NOT NULL,
    PRIMARY KEY CLUSTERED ([s_no] ASC),
    FOREIGN KEY ([ID]) REFERENCES [dbo].[Employerregisteration] ([Id])
);
CREATE TABLE [dbo].[Employerregisteration] (
    [Id]           NVARCHAR (50) NOT NULL,
    [Username]     NCHAR (20)    NULL,
    [CompanyName]  NCHAR (30)    NULL,
    [ManagerName]  NCHAR (30)    NULL,
    [Password]     NCHAR (40)    NULL,
    [State]        NCHAR (40)    NULL,
    [BranchID]     NVARCHAR (50) NULL,
    [Address]      TEXT          NULL,
    [Contact_no]   NCHAR (20)    NULL,
    [CompanyEmail] NCHAR (40)    NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC)
);

CREATE TABLE [dbo].[RegisterationTrainee] (
    [ID]                     NVARCHAR (50) NOT NULL,
    [UserName]               NCHAR (30)    NULL,
    [FirstName]              NCHAR (30)    NULL,
    [LastName]               NCHAR (30)    NULL,
    [Email]                  NCHAR (60)    NULL,
    [Date]                   DATE          NULL,
    [Password]               NCHAR (40)    NULL,
    [Country]                NCHAR (25)    NULL,
    [State]                  NCHAR (100)   NULL,
    [Address]                TEXT          NULL,
    [Contact]                NCHAR (20)    NULL,
    [license_number]         NCHAR (30)    NULL,
    [Social_security_number] NCHAR (50)    NULL,
    PRIMARY KEY CLUSTERED ([ID] ASC)
);
CREATE TABLE [dbo].[Traineeskills] (
    [S_NO]               INT            IDENTITY (1, 1) NOT NULL,
    [ID]                 NVARCHAR (50)  NULL,
    [Personal_statement] TEXT           NULL,
    [Skills]             TEXT           NULL,
    [Required_rate]      MONEY          NULL,
    [Available]          NVARCHAR (MAX) NULL,
    [Experience]         NVARCHAR (MAX) NULL,
    PRIMARY KEY CLUSTERED ([S_NO] ASC),
    FOREIGN KEY ([ID]) REFERENCES [dbo].[RegisterationTrainee] ([ID])
);

